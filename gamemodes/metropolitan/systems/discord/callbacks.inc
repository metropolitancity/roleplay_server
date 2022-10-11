#include <YSI_Coding\y_hooks>


hook OnGameModeInit()
{
    // configurando bot
    DCC_SetBotActivity(""SERVER_NAME" - 45.6.102.237:7777");
    /*

    new DCC_Channel:channel = DCC_FindChannelById("993305052091523154");
    new DCC_Embed:embed = DCC_CreateEmbed("Cidade em funcionamento!");
    DCC_SetEmbedColor(embed, 0x696969);
    DCC_SetEmbedFooter(embed, SERVER_NAME, "https://instagram.fsdu29-1.fna.fbcdn.net/v/t51.2885-19/308022724_145275318202855_1966990578263485840_n.jpg?stp=dst-jpg_s150x150&_nc_ht=instagram.fsdu29-1.fna.fbcdn.net&_nc_cat=107&_nc_ohc=23cDvFRRhSwAX_8UxBu&edm=AOQ1c0wBAAAA&ccb=7-5&oh=00_AT860er1l8um1RtoPUIKcPH_cTiBlGF8_QpSWrIejI9GWQ&oe=634B015F&_nc_sid=8fd12b");
    DCC_SetEmbedThumbnail(embed, "");
    DCC_AddEmbedField(embed, "Jogadores", "10", false);
    // enviar embed
    DCC_SendChannelEmbedMessage(channel, embed);*/
    return Y_HOOKS_CONTINUE_RETURN_1;
}