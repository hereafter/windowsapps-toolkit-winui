#include "pch.h"
#include "ConverterTools.h"

#include <winrt/Windows.Data.Json.h>
#include <concepts>
#include <sstream>

using namespace ::WindowsApps::Toolkit::WinUI::UI::Converters::Internals;
using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Data::Json;
using namespace winrt::Microsoft::UI::Xaml::Markup;


bool ConverterTools::TryParseBool(IInspectable const& parameter)
{
	auto parsed = false;

	if (parameter)
	{
		auto s = unbox_value_or(parameter, L"false");

		if (s == L"True" || s == L"1" || s == L"true" || s == L"TRUE")
		{
			parsed = true;
		}
	}

	return parsed;
}

double ConverterTools::TryParseDouble(IInspectable const& value)
{
	winrt::check_bool(value);
	double vd = 0.0;
	auto pv = value.try_as<IPropertyValue>();
	auto type = pv.Type();


	//TODO: this is !!HEAVY!???
	switch (type)
	{
	case PropertyType::Double:
	{
		vd = pv.GetDouble();
		break;
	}

	case PropertyType::Single:
	{
		vd = pv.GetSingle();
		break;
	}
	case PropertyType::String:
	{
		auto text = pv.GetString();
		try {
			vd = std::stod(text.c_str());
		}
		catch (...) {};
		break;
	}
	case PropertyType::UInt8:
	{
		vd = static_cast<double>(pv.GetUInt8());
		break;
	}

	case PropertyType::Int16:
	{
		vd = static_cast<double>(pv.GetInt16());
		break;
	}
	case PropertyType::UInt16:
	{
		vd = static_cast<double>(pv.GetUInt16());
		break;
	}

	case PropertyType::Int32:
	{
		vd = static_cast<double>(pv.GetInt32());
		break;
	}
	case PropertyType::UInt32:
	{
		vd = static_cast<double>(pv.GetUInt32());
		break;
	}

	case PropertyType::Int64:
	{
		vd = static_cast<double>(pv.GetInt64());
		break;
	}
	case PropertyType::UInt64:
	{
		vd = static_cast<double>(pv.GetUInt64());
		break;
	}

	default:
	{
		auto s = value.try_as<IStringable>();
		if (s)
		{
			auto text = s.ToString();
			try {
				vd = std::stod(text.c_str());
			}
			catch (...) {};
		}
		break;
	}
	}
	return vd;
}

int64_t ConverterTools::TryParseInt64(IInspectable const& value)
{
	winrt::check_bool(value);
	int64_t vd = 0;
	auto pv = value.try_as<IPropertyValue>();
	auto type = pv.Type();


	//TODO: this is !!HEAVY!???
	switch (type)
	{
		case PropertyType::Double:
		{
			vd = static_cast<int64_t>(pv.GetDouble());
			break;
		}

		case PropertyType::Single:
		{
			vd = static_cast<int64_t>(pv.GetSingle());
			break;
		}
		case PropertyType::String:
		{
			auto text = pv.GetString();
			try {
				vd = std::stoll(text.c_str());
			}
			catch (...) {};
			break;
		}
		case PropertyType::UInt8:
		{
			vd = static_cast<int64_t>(pv.GetUInt8());
			break;
		}

		case PropertyType::Int16:
		{
			vd = static_cast<int64_t>(pv.GetInt16());
			break;
		}
		case PropertyType::UInt16:
		{
			vd = static_cast<int64_t>(pv.GetUInt16());
			break;
		}

		case PropertyType::Int32:
		{
			vd = static_cast<int64_t>(pv.GetInt32());
			break;
		}
		case PropertyType::UInt32:
		{
			vd = static_cast<int64_t>(pv.GetUInt32());
			break;
		}

		case PropertyType::Int64:
		{
			vd = pv.GetInt64();
			break;
		}
		case PropertyType::UInt64:
		{
			vd = static_cast<int64_t>(pv.GetUInt64());
			break;
		}

		default:
		{
			auto s = value.try_as<IStringable>();
			if (s)
			{
				auto text = s.ToString();
				try {
					vd = std::stoll(text.c_str());
				}
				catch (...) {};
			}
			break;
		}
	}
	return vd;
}



IInspectable ConverterTools::Convert(IInspectable const& value, TypeName const& targetType)
{
	auto type = TypeName{ winrt::get_class_name(value) };
	if (type == targetType)
	{
		return value;
	}
	//TODO: check if value is targetype already to skip the convertion
	return XamlBindingHelper::ConvertValue(targetType, value);
}

hstring ConverterTools::ToFileSizeString(int64_t size)
{
	using namespace std;

	wostringstream ss;

	if (size < 1024)
	{
		ss.precision(1);
		ss << size << " bytes";
	}
	else if (size >> 10 < 1024)
	{
		ss.precision(2);
		ss << (size / 1024.0f) << " KB";
	}
	else if (size >> 20 < 1024)
	{
		ss.precision(2);
		ss << ((size >> 10) / 1024.0f) << " MB";
	}
	else if (size >> 30 < 1024)
	{
		ss.precision(2);
		ss << ((size >> 20) / 1024.0f) << " GB";
	}
	else if (size >> 40 < 1024)
	{
		ss.precision(2);
		ss << ((size >> 30) / 1024.0f) << " TB";
	}
	else if (size >> 50 < 1024)
	{
		ss.precision(2);
		ss << ((size >> 40) / 1024.0f) << " PB";
	}
	else
	{
		ss.precision(1);
		ss << ((size >> 50) / 1024.0f) << " EB";
	}

	return ss.str().c_str();
}