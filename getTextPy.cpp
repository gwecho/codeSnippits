String getTextPy(String str)
	{
		char ch[1024] = {0};
		memcpy(ch, str.c_str(), strlen(str.c_str()));
		int i = 0;
		String strPy = "";
		while (i < strlen(ch))
		{
			if (isgbk(ch[i], ch[i+1]))
			{
				int s = (int)(ch[i]&0xFF) * 256 + (int)(ch[i+1]&0xFF);
				if (s >= 45217 && s <= 45252) strPy += "A";
				else if (s >= 45253 && s <= 45760) strPy += "B";
				else if (s >= 45761 && s <= 46317) strPy += "C";
				else if (s >= 46318 && s <= 46825) strPy += "D";
				else if (s >= 46826 && s <= 47009) strPy += "E";
				else if (s >= 47010 && s <= 47296) strPy += "F";
				else if (s >= 47297 && s <= 47613) strPy += "G";
				else if (s >= 47614 && s <= 48118) strPy += "H";
				else if (s >= 48119 && s <= 49061) strPy += "J";
				else if (s >= 49062 && s <= 49323) strPy += "K";
				else if (s >= 49324 && s <= 49895) strPy += "L";
				else if (s >= 49896 && s <= 50370) strPy += "M";
				else if (s >= 50371 && s <= 50613) strPy += "N";
				else if (s >= 50614 && s <= 50621) strPy += "O";
				else if (s >= 50622 && s <= 50905) strPy += "P";
				else if (s >= 50906 && s <= 51386) strPy += "Q";
				else if (s >= 51387 && s <= 51445) strPy += "R";
				else if (s >= 51446 && s <= 52217) strPy += "S";
				else if (s >= 52218 && s <= 52697) strPy += "T";
				else if (s >= 52698 && s <= 52979) strPy += "W";
				else if (s >= 52980 && s <= 53640) strPy += "X";
				else if (s >= 53689 && s <= 54480) strPy += "Y";
				else if (s >= 54481 && s <= 62289) strPy += "Z";
				else strPy += "*";
				i += 2;
			}
			else
			{
				if (isprint(ch[i]))
					strPy += toupper(ch[i]);
				else
					strPy += "*";
				i += 1;
			}
		}
		return strPy;
	}
