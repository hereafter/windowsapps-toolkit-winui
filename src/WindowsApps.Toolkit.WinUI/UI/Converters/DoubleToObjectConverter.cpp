#include "pch.h"
#include "DoubleToObjectConverter.h"
#if __has_include("UI.Converters.DoubleToObjectConverter.g.cpp")
#include "UI.Converters.DoubleToObjectConverter.g.cpp"
#endif


using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::UI::Xaml::Interop;
using namespace winrt::Microsoft::UI::Xaml;
using namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation;


#pragma region Properties
#define __WATWUIC winrt::WindowsApps::Toolkit::WinUI::UI::Converters

DependencyProperty DoubleToObjectConverter::__trueValueProperty = DependencyProperty::Register(
	L"TrueValue",
	xaml_typename<IInspectable>(),
	xaml_typename<__WATWUIC::DoubleToObjectConverter>(),
	PropertyMetadata{ nullptr }
);

DependencyProperty DoubleToObjectConverter::__falseValueProperty = DependencyProperty::Register(
	L"FalseValue",
	xaml_typename<IInspectable>(),
	xaml_typename<__WATWUIC::DoubleToObjectConverter>(),
	PropertyMetadata{ nullptr }
);


DependencyProperty DoubleToObjectConverter::__nullValueProperty = DependencyProperty::Register(
	L"NullValue",
	xaml_typename<IInspectable>(),
	xaml_typename<__WATWUIC::DoubleToObjectConverter>(),
	PropertyMetadata{ nullptr }
);


DependencyProperty DoubleToObjectConverter::__greaterThanProperty = DependencyProperty::Register(
	L"GreaterThan",
	xaml_typename<double>(),
	xaml_typename<__WATWUIC::DoubleToObjectConverter>(),
	PropertyMetadata{ box_value(NAN) }
);


DependencyProperty DoubleToObjectConverter::__lessThanProperty = DependencyProperty::Register(
	L"LessThan",
	xaml_typename<double>(),
	xaml_typename<__WATWUIC::DoubleToObjectConverter>(),
	PropertyMetadata{ box_value(NAN) }
);


DependencyProperty DoubleToObjectConverter::TrueValueProperty()
{
	return __trueValueProperty;
}

DependencyProperty DoubleToObjectConverter::FalseValueProperty()
{
	return __falseValueProperty;
}

DependencyProperty DoubleToObjectConverter::NullValueProperty()
{
	return __nullValueProperty;
}

DependencyProperty DoubleToObjectConverter::GreaterThanProperty()
{
	return __greaterThanProperty;
}

DependencyProperty DoubleToObjectConverter::LessThanProperty()
{
	return __lessThanProperty;
}


IInspectable DoubleToObjectConverter::TrueValue()
{
	return this->GetValue(__trueValueProperty);
}

void DoubleToObjectConverter::TrueValue(IInspectable const& value)
{
	this->SetValue(__trueValueProperty, value);
}

IInspectable DoubleToObjectConverter::FalseValue()
{
	return this->GetValue(__falseValueProperty);
}

void DoubleToObjectConverter::FalseValue(IInspectable const& value)
{
	this->SetValue(__falseValueProperty, value);
}

IInspectable DoubleToObjectConverter::NullValue()
{
	return this->GetValue(__nullValueProperty);
}

void DoubleToObjectConverter::NullValue(IInspectable const& value)
{
	this->SetValue(__nullValueProperty, value);
}

double DoubleToObjectConverter::GreaterThan()
{
	return unbox_value<double>(this->GetValue(__greaterThanProperty));
}

void DoubleToObjectConverter::GreaterThan(double value)
{
	this->SetValue(__greaterThanProperty, box_value(value));
}

double DoubleToObjectConverter::LessThan()
{
	return unbox_value<double>(this->GetValue(__lessThanProperty));
}

void DoubleToObjectConverter::LessThan(double value)
{
	this->SetValue(__lessThanProperty, box_value(value));
}

#pragma endregion



IInspectable DoubleToObjectConverter::Convert(IInspectable const& value, TypeName const& targetType, IInspectable const& parameter, hstring const& language)
{
	if (!value) return this->NullValue();

	double vd = 0.0;

	auto pv = value.try_as<IPropertyValue>();
	auto type = pv.Type();

	switch (type)
	{
	default:
		vd = 0.0f;
	}



	return nullptr;
}

IInspectable DoubleToObjectConverter::ConvertBack(IInspectable const&, TypeName const&, IInspectable const&, hstring const&)
{
	hresult hr{ E_NOTIMPL };
	throw_hresult(hr);
}
