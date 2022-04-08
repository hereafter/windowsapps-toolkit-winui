#include "pch.h"
#include "DoubleToVisibilityConverter.h"
#if __has_include("UI.Converters.DoubleToVisibilityConverter.g.cpp")
#include "UI.Converters.DoubleToVisibilityConverter.g.cpp"
#endif

using namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation;


DoubleToVisibilityConverter::DoubleToVisibilityConverter()
{
	this->TrueValue(box_value(Visibility::Visible));
	this->FalseValue(box_value(Visibility::Collapsed));
	this->NullValue(box_value(Visibility::Collapsed));
}