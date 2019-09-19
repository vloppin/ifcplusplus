/* -*-c++-*- IfcQuery www.ifcquery.com
*
MIT License

Copyright (c) 2017 Fabian Gerold

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include "BuildingException.h"

BuildingException::BuildingException(const std::string& reason)
{
	m_reason_str = reason;
}

BuildingException::BuildingException(const std::string& reason, const char* function_name)
{
	m_reason_str.append(function_name);
	if (!reason.empty())
	{
		m_reason_str.append(": ");
		m_reason_str.append(reason);
	}
}

BuildingException::BuildingException(const std::wstring& reason)
{
	m_reason_str.assign(reason.begin(), reason.end());
}

BuildingException::BuildingException(const std::wstring& reason, const char* function_name)
{
	m_reason_str.append(function_name);
	if (!reason.empty())
	{
		m_reason_str.append(": ");
		std::string reason_str;
		reason_str.assign(reason.begin(), reason.end());
		m_reason_str.append(reason_str);
	}
}

const char* BuildingException::what() const noexcept
{
	return m_reason_str.c_str();
}

OutOfMemoryException::OutOfMemoryException()
{
	m_reason_str = "Out of memory";
}

OutOfMemoryException::OutOfMemoryException(const char* function_name)
{
	m_reason_str = "Out of memory in function: ";
	m_reason_str.append(function_name);
}

const char* OutOfMemoryException::what() const noexcept
{
	return m_reason_str.c_str();
}
