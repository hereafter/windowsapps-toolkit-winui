#include "pch.h"
#include "VisibilityToBoolConverter.h"
#if __has_include("UI.Converters.VisibilityToBoolConverter.g.cpp")
#include "UI.Converters.VisibilityToBoolConverter.g.cpp"
#endif

using namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation;


IInspectable VisibilityToBoolConverter::Convert(IInspectable const& value, TypeName const&, IInspectable const&, hstring const&)
{
	if (!value) return box_value(false);

	auto convertable=value.try_as<Visibility>();
	if (!convertable) return box_value(false);

	auto v = value.as<Visibility>();
	return box_value(v==Visibility::Visible);
}

IInspectable VisibilityToBoolConverter::ConvertBack(IInspectable const& value, TypeName const&, IInspectable const&, hstring const&)
{
	auto boolValue = (value && unbox_value_or(value, false));
	return box_value((boolValue ? Visibility::Visible : Visibility::Collapsed));
}