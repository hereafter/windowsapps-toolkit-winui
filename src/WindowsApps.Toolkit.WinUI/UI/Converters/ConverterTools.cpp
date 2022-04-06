#include "pch.h"
#include "ConverterTools.h"

#include <winrt/Windows.Data.Json.h>
#include <concepts>

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
		auto s=unbox_value_or(parameter, L"false");
		
		if (s == L"True" || s == L"1" || s == L"true")
		{
			parsed = true;
		}
	}

	return parsed;
}


IInspectable ConverterTools::Convert(IInspectable const& value, TypeName const& targetType)
{
	//TODO: check if value is targetype already to skip the convertion
	return XamlBindingHelper::ConvertValue(targetType, value);
}