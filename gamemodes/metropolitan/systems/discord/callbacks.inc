#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    DCC_SetBotActivity(""SERVER_NAME" - 186.233.117.189:7777");
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    if ( clickedid == INVALID_TEXT_DRAW && GetPVarInt(playerid, "DC:ShowIntegration") ) {
        SelectTextDraw(playerid, COLOR_ORANGE);
        return Y_HOOKS_BREAK_RETURN_1;
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if ( !GetPVarInt(playerid, "DC:ShowIntegration") )return Y_HOOKS_CONTINUE_RETURN_1;
    
    if ( playertextid == PTD_DiscordIntegration[playerid][5] ) // input discord
    {
        Dialog_Show(playerid, INPUT_DISCORD_ID, DIALOG_STYLE_INPUT, "DISCORD ID", "{"COLOR_WHITE_EMBED"}Digite o ID do seu usuário no discord\nSe tiver dúvida abra um ticket em nosso discord.", "Confirmar", "Fechar");
        return Y_HOOKS_BREAK_RETURN_1;
    }
    else if ( playertextid == PTD_DiscordIntegration[playerid][6] ) //  confirmar
    {
        if ( isnull(InputDiscordID[playerid]) )
        {
            NT:Send(playerid, NT_TYPE_ERROR, "Você precisa digitar o ID do seu discord.");
            return Y_HOOKS_BREAK_RETURN_1;
        }

        if ( GetPVarInt(playerid, "IsDiscordChecking") )
        {
            NT:Send(playerid, NT_TYPE_ERROR, "Aguarde...");
            return Y_HOOKS_BREAK_RETURN_1;
        }

        new DCC_User:user = DCC_FindUserById(InputDiscordID[playerid]);
        if ( user == DCC_INVALID_USER )
        {
            NT:Send(playerid, NT_TYPE_ERROR, "Código inválido, não encontramos esse usuário em nosso discord.");
            return Y_HOOKS_BREAK_RETURN_1;
        }

        new query[128];
        mysql_format(SQL_Connection, query, sizeof(query), "SELECT id FROM "TABLE_USERS" WHERE `discord_id`='%e';", InputDiscordID[playerid]);
        new Cache:cache = mysql_query(SQL_Connection, query, true);

        if ( cache_num_rows() )
        {
            cache_delete(cache);
            NT:Send(playerid, NT_TYPE_ERROR, "Esse usuário já esta integrado com nosso discord.");
            return Y_HOOKS_BREAK_RETURN_1;
        }
        cache_delete(cache);
        SetPVarInt(playerid, "IsDiscordChecking", 1);
        DCC_CreatePrivateChannel(user, "DC_OnCreateDM", "i", playerid);
        return Y_HOOKS_BREAK_RETURN_1;
    }
    return Y_HOOKS_BREAK_RETURN_1;
}

forward DC_OnCreateDM(playerid);
public DC_OnCreateDM(playerid)
{
    
    new DCC_Channel:channel = DCC_GetCreatedPrivateChannel();
    if ( channel != DCC_INVALID_CHANNEL )
    {
        new DCC_Embed:embed = DCC_CreateEmbed(), passaporte[20];
        valstr(passaporte, Player[playerid][ID]);

        DCC_SetEmbedDescription(embed, "Verifique os dados abaixo.\nReaja com :white_check_mark: para confirmar\nReaja com :x: para recusar.");
        DCC_SetEmbedColor(embed, 0x202020);
        DCC_SetEmbedThumbnail(embed, "https://instagram.fsdu29-1.fna.fbcdn.net/v/t51.2885-19/308022724_145275318202855_1966990578263485840_n.jpg?stp=dst-jpg_s150x150&_nc_ht=instagram.fsdu29-1.fna.fbcdn.net&_nc_cat=107&_nc_ohc=4int3bTr6u4AX8cp6SP&edm=AOQ1c0wBAAAA&ccb=7-5&oh=00_AT93CRfXeFttjJc96BQIG6x7mWECAjDUoBVQZB_MENK9jw&oe=6352EA5F&_nc_sid=8fd12b");
        DCC_AddEmbedField(embed, "Passaporte", passaporte, true);
        DCC_AddEmbedField(embed, "Nome", Player[playerid][Name], true);
        DCC_AddEmbedField(embed, "Ultimo Login", Player[playerid][LastLogin]);
        DCC_SendChannelEmbedMessage(channel, embed, "", "DC_OnSendMessage", "i", playerid);
        return 1;
    }
    NT:Send(playerid, NT_TYPE_ERROR, "Não foi possível lhe enviar uma mensagem no DM do discord.");
    return 0;
}

forward DC_OnSendMessage(playerid);
public DC_OnSendMessage(playerid)
{
    new DCC_Message:message = DCC_GetCreatedMessage();
    if ( message )
    {
        new DCC_Emoji:accept = DCC_CreateEmoji("✅");
        new DCC_Emoji:deny = DCC_CreateEmoji("❌");
        DCC_CreateReaction(message, accept);
        DCC_CreateReaction(message, deny);
        DCC_SetMessagePersistent(message, true);

        new query[128];
        mysql_format(SQL_Connection, query, sizeof(query), "UPDATE "TABLE_USERS" SET `discord_id`='%e' WHERE `id`='%d';", InputDiscordID[playerid], Player[playerid][ID]);
        mysql_tquery(SQL_Connection, query);
        NT:Send(playerid, NT_TYPE_SUCCESS, "Verifique o DM no seu discord para prosseguir sua verificação.");
        DC:HideIntegration(playerid);
        return Player:Kick(playerid), 1;
    }
    return 0;
}

public DCC_OnMessageReaction(DCC_Message:message, DCC_User:reaction_user, DCC_Emoji:emoji, DCC_MessageReactionType:reaction_type)
{
    new bool:is_bot;
    DCC_IsUserBot(reaction_user, is_bot);

    if ( is_bot )return 0;

    switch(reaction_type)
    {
        case REACTION_ADD:
        {
            new emoji_name[DCC_EMOJI_NAME_SIZE],
                DCC_Guild:guild = DCC_FindGuildById("992951237853073451"),
                discord_id[DCC_ID_SIZE],
                DCC_Role:role = DCC_FindRoleById("993311538859487282"),
                DCC_Channel:channel = DCC_INVALID_CHANNEL,
                bool:has_role
            ;
        
            DCC_HasGuildMemberRole(guild, reaction_user, role, has_role);
            if ( has_role )return 0;
            
            DCC_GetEmojiName(emoji, emoji_name);

            if ( !strcmp(emoji_name, "✅", false) )
            {
                DCC_GetUserId(reaction_user, discord_id);

                new query[128];
                mysql_format(SQL_Connection, query, sizeof(query), "UPDATE "TABLE_USERS" SET `discord`=1 WHERE `discord_id`='%e'", discord_id);
                new Cache:cache = mysql_query(SQL_Connection, query, true);
                if ( cache_affected_rows() )
                {
                    DCC_GetMessageChannel(message, channel);
                    DCC_DeleteMessage(message);

                    DCC_AddGuildMemberRole(guild, reaction_user, role); // adicionar cargo ao jogador

                    new DCC_Embed:embed = DCC_CreateEmbed();
                    DCC_SetEmbedDescription(embed, "✅ Conta vinculado com sucesso!");
                    DCC_SetEmbedColor(embed, 0x202020);
                    DCC_SendChannelEmbedMessage(channel, embed);
                }
                cache_delete(cache);                
                return 1;
            }
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}