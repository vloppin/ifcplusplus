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

#pragma once

#include <exception>
#include <string>

#define __FUNC__ __FUNCTION__
#define _func_ __FUNCTION__

class BuildingException : public std::exception
{
public:
	BuildingException(const std::string& reason);

	BuildingException(const std::string& reason, const char* function_name);

	BuildingException(const std::wstring& reason);

	BuildingException(const std::wstring& reason, const char* function_name);

	~BuildingException() noexcept override = default;

	const char* what() const noexcept override;

	std::string m_reason_str;
};

class OutOfMemoryException : public std::exception
{
public:
	OutOfMemoryException();

	OutOfMemoryException(const char* function_name);

	~OutOfMemoryException() noexcept override = default;

	const char* what() const noexcept override;

	std::string m_reason_str;
};
