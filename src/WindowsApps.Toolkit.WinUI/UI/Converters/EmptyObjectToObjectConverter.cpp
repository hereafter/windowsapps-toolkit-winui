#include "pch.h"
#include "EmptyObjectToObjectConverter.h"
#if __has_include("UI.Converters.EmptyObjectToObjectConverter.g.cpp")
#include "UI.Converters.EmptyObjectToObjectConverter.g.cpp"
#endif

using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::UI::Xaml::Interop;
using namespace winrt::Microsoft::UI::Xaml;

using namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation;

#pragma region Properties

#define __WATWUIC winrt::WindowsApps::Toolkit::WinUI::UI::Converters

DependencyProperty EmptyObjectToObjectConverter::__emptyValueProperty = DependencyProperty::Register(
	L"EmptyValue", 
	xaml_typename<IInspectable>(), 
	xaml_typename<__WATWUIC::EmptyObjectToObjectConverter>(),
	PropertyMetadata{nullptr}
);

DependencyProperty EmptyObjectToObjectConverter::__notEmptyValueProperty = DependencyProperty::Register(
	L"NotEmptyValue", 
	xaml_typename<IInspectable>(),
	xaml_typename<__WATWUIC::EmptyObjectToObjectConverter>(),
	PropertyMetadata{ nullptr }
);

DependencyProperty EmptyObjectToObjectConverter::EmptyValueProperty()
{
	return __emptyValueProperty;
}

DependencyProperty EmptyObjectToObjectConverter::NotEmptyValueProperty()
{
	return __notEmptyValueProperty;
}

#pragma endregion


IInspectable EmptyObjectToObjectConverter::EmptyValue()
{
	return this->GetValue(__emptyValueProperty);
}

void EmptyObjectToObjectConverter::EmptyValue(IInspectable value)
{
	this->SetValue(__emptyValueProperty, value);
}

IInspectable EmptyObjectToObjectConverter::NotEmptyValue()
{
	return this->GetValue(__notEmptyValueProperty);
}

void EmptyObjectToObjectConverter::NotEmptyValue(IInspectable value)
{
	this->SetValue(__notEmptyValueProperty, value);
}

IInspectable EmptyObjectToObjectConverter::Convert(IInspectable const& value, TypeName const& targetType, IInspectable const& parameter, hstring const& language)
{
	return nullptr;
}

IInspectable EmptyObjectToObjectConverter::ConvertBack(IInspectable const& value, TypeName const& targetType, IInspectable const& parameter, hstring const& language)
{
	return nullptr;
}


bool EmptyObjectToObjectConverter::CheckValueIsEmpty(IInspectable value)
{
	return false;
}