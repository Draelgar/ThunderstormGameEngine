/*****************************************************************************************
** Author: Gustaf Peter Hultgren
** Date: 2017-04-08
** © 2017, Gustaf Peter Hultgren, All Rights Reserved.
******************************************************************************************/
#include "IniFile.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool ts::file::IniFile::Load(std::string filePath)
{
	size_t index = filePath.find_last_of(".");
	if (index != -1)
	{
		string fileEnding = "";
		for (size_t i = index + 1; i < filePath.length(); i++)
		{
			char character = filePath.at(i);
			if (character <= 'Z' && character >= 'A')
			{
				fileEnding += character + (char)32;
			}
			else
			{
				fileEnding += character;
			}
		}

		// Was the ending "ini"?
		if (fileEnding == "ini")
		{
			ifstream inFileStream(filePath.c_str());

			if (inFileStream.is_open())
			{
				string line = "";
				bool startedSection = false;
				bool startedParameter = false;
				string data = "";
				string parameter = "";
				ini::Section *sectionPtr = NULL;
				char character = NULL;

				while (getline(inFileStream, line))
				{
					// TODO:
					// - Parse each character separately.
					// - Check for comments and ignore them
					// - Check for sections
					// - Check for parameters (if no sections are found yet, ignore parameters).
					cout << line << endl;
					for (size_t i = 0; i < line.length(); i++)
					{
						character = line.at(i);
						// Is this a comment?
						if (character == ';')
						{
							// Then discard the rest of this line.
							break;
						}
						// Is this the start of a section?
						else if (character == '[')
						{
							// Mark it as the start of a section.
							if (!startedSection)
							{
								startedSection = true;
							}
							else
							{
								// The file was corrupted!
								inFileStream.close();
								return false;
							}
						}
						// End of section.
						else if (character == ']')
						{
							if (startedSection)
							{
								// Create the new section.
								startedSection = false;
								if (data.length() > 0)
								{
									mSections.insert_or_assign(data, ini::Section());
									sectionPtr = &mSections.at(data);
									data = "";
								}
								else
								{
									// The file was corrupted!
									inFileStream.close();
									return false;
								}
							}
							else
							{
								// The file was corrupted!
								inFileStream.close();
								return false;
							}
						}
						// End of parameter name.
						else if (character == '=')
						{
							if (!startedSection && data.length() > 0 && !startedParameter)
							{
								parameter = "";
								parameter = data;
								data = "";
								startedParameter = true;
							}
							else if (startedSection || startedParameter)
							{
								inFileStream.close();
								return false;
							}
						}
						// Is this not a white space?
						else if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') 
							|| (character >= '0' && character <= '9'))
						{
							data += character;
						}
						else if (character == ' ')
						{
							if (startedParameter && sectionPtr != NULL)
							{
								startedParameter = false;
								sectionPtr->Insert(parameter, data);
							}

							data = "";
						}
					}
				}

				inFileStream.close();

			}

			return true;

		}
	}

	return false;
}

bool ts::file::IniFile::Save(std::string filePath)
{
	ofstream outFileStream(filePath.c_str());

	if (outFileStream.is_open())
	{
		map<string, ini::Section>::iterator it = mSections.begin();

		while(it != mSections.end())
		{
			// Add the name of the section.
			outFileStream << "[" + it->first + "]" << endl;
		
			// Add the parameters and their values.
			vector<string> parameters = it->second.GetValues();
			for (size_t i = 0; i < parameters.size(); i++)
			{
				outFileStream << parameters[i] << endl;
			}

			outFileStream << endl; // Add an extra empty row after each section.
			it++;
		}

		outFileStream.close();
		return true;
	}

	return false;
}
