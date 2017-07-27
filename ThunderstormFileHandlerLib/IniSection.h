/*****************************************************************************************
** Author: Gustaf Peter Hultgren
** Date: 2017-04-08
** © 2017, Gustaf Peter Hultgren, All Rights Reserved.
******************************************************************************************/
#pragma once

#include <map>
#include <vector>

namespace ts
{
	namespace file
	{
		namespace ini
		{
			/** This class represents a section within a ini file. **/
			class Section
			{
			private:
				std::map<std::string, std::string> mData;

			public:
				/** Create a new section. **/
				Section()
				{
					mData = std::map<std::string, std::string>();
				};

				/** Get the selected parameter. **/
				inline std::string GetValue(std::string parameter) { return mData.at(parameter); }

				/** Insert the selected parameter value. **/
				inline void Insert(std::string parameter, std::string value) { mData.insert_or_assign(parameter, value); };

				/** Get all values. **/
				inline std::vector<std::string> GetValues()
				{ 
					std::map<std::string, std::string>::iterator it = mData.begin();
					std::vector<std::string> strings = std::vector<std::string>();
					while (it != mData.end())
					{
						strings.push_back(it->first + "=\"" + it->second + "\"");
						it++;
					}
					return strings;
				};
			};

		}
	}
}