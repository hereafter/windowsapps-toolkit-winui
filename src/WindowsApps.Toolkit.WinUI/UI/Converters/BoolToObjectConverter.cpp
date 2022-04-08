#include "pch.h"
#include "BoolToObjectConverter.h"
#if __has_include("UI.Converters.BoolToObjectConverter.g.cpp")
#include "UI.Converters.BoolToObjectConverter.g.cpp"
#endif

#include "ConverterTools.h"

using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::UI::Xaml::Interop;
using namespace winrt::Microsoft::UI::Xaml;
using namespace ::WindowsApps::Toolkit::WinUI::UI::Converters::Internals;

using namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation;

#pragma region Properties
#define __WATWUIC winrt::WindowsApps::Toolkit::WinUI::UI::Converters

DependencyProperty BoolToObjectConverter::__trueValueProperty = DependencyProperty::Register(
	L"TrueValue",
	xaml_typename<IInspectable>(),
	xaml_typename<__WATWUIC::EmptyObjectToObjectConverter>(),
	PropertyMetadata{ nullptr }
);

DependencyProperty BoolToObjectConverter::__falseValueProperty = DependencyProperty::Register(
	L"FalseValue",
	xaml_typename<IInspectable>(),
	xaml_typename<__WATWUIC::EmptyObjectToObjectConverter>(),
	PropertyMetadata{ nullptr }
);

DependencyProperty BoolToObjectConverter::TrueValueProperty()
{
	return __trueValueProperty;
}

DependencyProperty BoolToObjectConverter::FalseValueProperty()
{
	return __falseValueProperty;
}

#pragma endregion




IInspectable BoolToObjectConverter::TrueValue()
{
	return this->GetValue(__trueValueProperty);
}

void BoolToObjectConverter::TrueValue(IInspectable value)
{
	this->SetValue(__trueValueProperty, value);
}

IInspectable BoolToObjectConverter::FalseValue()
{
	return this->GetValue(__falseValueProperty);
}

void BoolToObjectConverter::FalseValue(IInspectable value)
{
	this->SetValue(__falseValueProperty, value);
}

IInspectable BoolToObjectConverter::Convert(IInspectable const& value, TypeName const& targetType, IInspectable const& parameter, hstring const&)
{	
	auto boolValue = unbox_value_or(value, false);
	// Negate if needed
	if (ConverterTools::TryParseBool(parameter))
	{
		boolValue = !boolValue;
	}

	return ConverterTools::Convert(boolValue ? TrueValue() : FalseValue(), targetType);
}

IInspectable BoolToObjectConverter::ConvertBack(IInspectable const& value, TypeName const&, IInspectable const& parameter, hstring const&)
{
	TypeName valueType{ winrt::get_class_name(value) };
	auto tmp = ConverterTools::Convert(TrueValue(), valueType);

	auto pv1 = value.try_as<IPropertyValue>();
	auto pv2 = tmp.try_as<IPropertyValue>();
	auto result = (pv1 == pv2);

	if (ConverterTools::TryParseBool(parameter))
	{
		result = !result;
	}

	return box_value(result);
}

