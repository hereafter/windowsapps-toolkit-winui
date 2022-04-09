#include "pch.h"
#include "StringFormatConverter.h"
#if __has_include("UI.Converters.StringFormatConverter.g.cpp")
#include "UI.Converters.StringFormatConverter.g.cpp"
#endif

#include <cstdarg>
#include <wil/resource.h>

using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::UI::Xaml::Interop;
using namespace winrt::Microsoft::UI::Xaml;
using namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation;

using namespace std;

IInspectable StringFormatConverter::Convert(IInspectable const& value, TypeName const&, IInspectable const& parameter, hstring const&)
{	
	using namespace wil;

	if (!value) return nullptr;
	if (!parameter) return value;

	auto format = unbox_value_or(parameter, L"");
	auto&& f = format.c_str();

	//TODO: std format not stable yet as C++ 20??

	auto pv = value.try_as<IPropertyValue>();
	if (!pv) return value;

	auto type = pv.Type();	
	switch (type)
	{
		case PropertyType::Boolean:
		{
			auto s = pv.GetBoolean() ? L"true" : L"false";
			auto r = str_printf_failfast<unique_cotaskmem_string>(f, s);
			return box_value(r.get());;
		}
		case PropertyType::Double:
		{
			auto v= pv.GetDouble();
			auto r = str_printf_failfast<unique_cotaskmem_string>(f, v);
			return box_value(r.get());;
		}
		case PropertyType::Single:
		{
			auto v = pv.GetSingle();
			auto r = str_printf_failfast<unique_cotaskmem_string>(f, v);
			return box_value(r.get());;
		}

		case PropertyType::UInt8:
		{
			auto v = pv.GetUInt8();
			auto r = str_printf_failfast<unique_cotaskmem_string>(f, v);
			return box_value(r.get());;
		}

		case PropertyType::Int16:
		{
			auto v = pv.GetInt16();
			auto r = str_printf_failfast<unique_cotaskmem_string>(f, v);
			return box_value(r.get());;
		}

		case PropertyType::UInt16:
		{
			auto v = pv.GetUInt16();
			auto r = str_printf_failfast<unique_cotaskmem_string>(f, v);
			return box_value(r.get());;
		}

		case PropertyType::Int32:
		{
			auto v = pv.GetInt32();
			auto r = str_printf_failfast<unique_cotaskmem_string>(f, v);
			return box_value(r.get());;
		}

		case PropertyType::UInt32:
		{
			auto v = pv.GetUInt32();
			auto r = str_printf_failfast<unique_cotaskmem_string>(f, v);
			return box_value(r.get());;
		}

		case PropertyType::Int64:
		{
			auto v = pv.GetInt64();
			auto r = str_printf_failfast<unique_cotaskmem_string>(f, v);
			return box_value(r.get());;
		}

		case PropertyType::UInt64:
		{
			auto v = pv.GetUInt64();
			auto r = str_printf_failfast<unique_cotaskmem_string>(f, v);
			return box_value(r.get());;
		}

		case PropertyType::Point:
		{
			auto point = pv.GetPoint();
			wostringstream ss;
			ss << point.X << "," << point.Y;
			auto r = str_printf_failfast<unique_cotaskmem_string>(f, ss.str().c_str());
			return box_value(r.get());;
		}

		case PropertyType::Size:
		{
			auto size = pv.GetSize();
			wostringstream ss;
			ss << size.Width << "," << size.Height;
			auto r = str_printf_failfast<unique_cotaskmem_string>(f, ss.str().c_str());
			return box_value(r.get());;
		}
		
		case PropertyType::Rect:
		{
			auto rect = pv.GetRect();
			wostringstream ss; 
			ss << rect.X << "," << rect.Y << "," << rect.Width << "," << rect.Height;
			auto r = str_printf_failfast<unique_cotaskmem_string>(f, ss.str().c_str());
			return box_value(r.get());;
		}

		case PropertyType::String:
		{
			auto s = pv.GetString();
			auto r = str_printf_failfast<unique_cotaskmem_string>(f, s.c_str());
			return box_value(r.get());
		}

		default: //stringable
		{
			auto s=pv.try_as<IStringable>();
			if (!s) return value;

			auto r = str_printf_failfast<unique_cotaskmem_string>(f, s.ToString().c_str());
			return box_value(r.get());
		}
	}

}

IInspectable StringFormatConverter::ConvertBack(IInspectable const&, TypeName const&, IInspectable const&, hstring const&)
{
	throw_hresult({ E_NOTIMPL });
}