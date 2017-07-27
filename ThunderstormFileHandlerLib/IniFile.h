/*****************************************************************************************
** Author: Gustaf Peter Hultgren
** Date: 2017-04-08
** © 2017, Gustaf Peter Hultgren, All Rights Reserved.
******************************************************************************************/
#pragma once

#include "IniSection.h"

namespace ts
{
	namespace file
	{
		/** This is a virtual representation of an ini file. **/
		class IniFile {
		private:
			std::map<std::string, ini::Section> mSections;

		public:
			/** Create a new ini file. **/
			IniFile() { mSections = std::map<std::string, ini::Section>(); };

			/** Get the selected section by its name. **/
			inline std::string Get(std::string section, std::string parameter) { return mSections.at(section).GetValue(parameter); };

			inline ini::Section &Get(std::string section) { return mSections.at(section); };

			/** Insert the given section object into the desired place in the map. **/
			inline void Insert(std::string sectionName, ini::Section sectionObject) { mSections.insert_or_assign(sectionName, sectionObject); };

			/** Insert the parameter to the selected section. **/
			inline void Insert(std::string section, std::string parameter, std::string value)
			{
				mSections.at(section).Insert(parameter, value);
			};

			/** Load the file. **/
			bool Load(std::string filePath);

			/** Save the contents onto a file. **/
			bool Save(std::string filePath);
		};
	}
}