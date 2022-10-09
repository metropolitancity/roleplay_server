stock FixText(const string[])
{
    new szFixed[1024], iPos, iLen;

    for(iLen = strlen(string); iPos < iLen; iPos ++)
        switch(string[iPos])
        {
            case '%':          szFixed[iPos] = 37;
            case '&':          szFixed[iPos] = 38;
            case '¡':          szFixed[iPos] = 64;
            case '°':          szFixed[iPos] = 124;
            case 'À':          szFixed[iPos] = 128;
            case 'Á':          szFixed[iPos] = 129;
            case 'Â':          szFixed[iPos] = 130;
            case 'Ä', 'Ã':     szFixed[iPos] = 131;
            case 'Ç':          szFixed[iPos] = 133;
            case 'È':          szFixed[iPos] = 134;
            case 'É':          szFixed[iPos] = 135;
            case 'Ê':          szFixed[iPos] = 136;
            case 'Ë':          szFixed[iPos] = 137;
            case 'Ì':          szFixed[iPos] = 138;
            case 'Í':          szFixed[iPos] = 139;
            case 'Î':          szFixed[iPos] = 140;
            case 'Ï':          szFixed[iPos] = 141;
            case 'Ò':          szFixed[iPos] = 142;
            case 'Ó':          szFixed[iPos] = 143;
            case 'Ô':          szFixed[iPos] = 144;
            case 'Ö', 'Õ':     szFixed[iPos] = 145;
            case 'Ù':          szFixed[iPos] = 146;
            case 'Ú':          szFixed[iPos] = 147;
            case 'Û':          szFixed[iPos] = 148;
            case 'Ü':          szFixed[iPos] = 149;
            case 'à':          szFixed[iPos] = 151;
            case 'á':          szFixed[iPos] = 152;
            case 'â':          szFixed[iPos] = 153;
            case 'ä', 'ã':     szFixed[iPos] = 154;
            case 'ç':          szFixed[iPos] = 156;
            case 'è':          szFixed[iPos] = 157;
            case 'é':          szFixed[iPos] = 158;
            case 'ê':          szFixed[iPos] = 159;
            case 'ë':          szFixed[iPos] = 160;
            case 'ì':          szFixed[iPos] = 161;
            case 'í':          szFixed[iPos] = 162;
            case 'î':          szFixed[iPos] = 163;
            case 'ï':          szFixed[iPos] = 164;
            case 'ò':          szFixed[iPos] = 165;
            case 'ó':          szFixed[iPos] = 166;
            case 'ô':          szFixed[iPos] = 167;
            case 'ö', 'õ':     szFixed[iPos] = 168;
            case 'ù':          szFixed[iPos] = 169;
            case 'ú':          szFixed[iPos] = 170;
            case 'û':          szFixed[iPos] = 171;
            case 'ü':          szFixed[iPos] = 172;
            case 'Ñ':          szFixed[iPos] = 173;
            case 'ñ':          szFixed[iPos] = 174;
            case '¿':          szFixed[iPos] = 175;
            case '`':          szFixed[iPos] = 177;
            default:           szFixed[iPos] = string[iPos];
        }

    return szFixed;
} 


stock Text:TextDrawCreate_fix(Float:x, Float:y, const text[])
{
	return TextDrawCreate(x, y, FixText(text));
}
#if defined _ALS_TextDrawCreate
	#undef TextDrawCreate
#else 
	#define _ALS_TextDrawCreate
#endif

#define TextDrawCreate TextDrawCreate_fix

stock TextDrawSetString_fix(Text:TextDraw, const text[])
{
	return TextDrawSetString(TextDraw, FixText(text));
}
#if defined _ALS_TextDrawSetString
	#undef TextDrawSetString
#else 
	#define _ALS_TextDrawSetString
#endif

#define TextDrawSetString TextDrawSetString_fix

stock PlayerText:CreatePlayerTextDraw_fix(playerid, Float:x, Float:y, const text[])
{
	return CreatePlayerTextDraw(playerid, x, y, FixText(text));
}
#if defined _ALS_CreatePlayerTextDraw
	#undef CreatePlayerTextDraw
#else 
	#define _ALS_CreatePlayerTextDraw
#endif

#define CreatePlayerTextDraw CreatePlayerTextDraw_fix

stock PlayerTextDrawSetString_fix(playerid, PlayerText:Playertext, const text[])
{
	return PlayerTextDrawSetString(playerid, Playertext, FixText(text));
}
#if defined _ALS_PlayerTextDrawSetString
	#undef PlayerTextDrawSetString
#else 
	#define _ALS_PlayerTextDrawSetString
#endif

#define PlayerTextDrawSetString PlayerTextDrawSetString_fix

stock GameTextForPlayer_fix(playerid, const string[], time, style)
{
	return GameTextForPlayer(playerid, FixText(string), time, style);
}
#if defined _ALS_GameTextForPlayer
	#undef GameTextForPlayer
#else 
	#define _ALS_GameTextForPlayer
#endif

#define GameTextForPlayer GameTextForPlayer_fix

stock GameTextForAll_fix(string[], time, style)
{
	return GameTextForAll(FixText(string), time, style);
}
#if defined _ALS_GameTextForAll
	#undef GameTextForAll
#else 
	#define _ALS_GameTextForAll
#endif

#define GameTextForAll GameTextForAll_fix

stock cache_get_value_name_int_fix(row_idx, const column_name[], &destination)
{
    new bool:null;
    cache_is_value_name_null(row_idx, column_name, null);
    if ( null ) {
        destination = 0;
        return 1;
    }
    return cache_get_value_name_int(row_idx, column_name, destination);
}
#if defined _ALS_cache_get_value_name_int
    #undef cache_get_value_name_int
#else
    #define _ALS_cache_get_value_name_int
#endif
#define cache_get_value_name_int cache_get_value_name_int_fix


stock cache_get_value_name_bool_fix(row_idx, const column_name[], &bool:destination)
{
    new bool:null;
    cache_is_value_name_null(row_idx, column_name, null);
    if ( null ) {
        destination = false;
        return 1;
    }
    return cache_get_value_name_bool(row_idx, column_name, destination);
}
#if defined _ALS_cache_get_value_name_bool
    #undef cache_get_value_name_bool
#else
    #define _ALS_cache_get_value_name_bool
#endif
#define cache_get_value_name_bool cache_get_value_name_bool_fix