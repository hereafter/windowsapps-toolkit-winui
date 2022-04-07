#include "pch.h"
#include "BoolToVisibilityConverter.h"
#if __has_include("UI.Converters.BoolToVisibilityConverter.g.cpp")
#include "UI.Converters.BoolToVisibilityConverter.g.cpp"
#endif

using namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation;

BoolToVisibilityConverter::BoolToVisibilityConverter()
{
	this->TrueValue(box_value(Visibility::Visible));
	this->FalseValue(box_value(Visibility::Collapsed));
}
