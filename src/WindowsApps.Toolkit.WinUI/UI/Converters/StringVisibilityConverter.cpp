#include "pch.h"
#include "StringVisibilityConverter.h"
#if __has_include("UI.Converters.StringVisibilityConverter.g.cpp")
#include "UI.Converters.StringVisibilityConverter.g.cpp"
#endif

using namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation;

StringVisibilityConverter::StringVisibilityConverter()
{
	this->EmptyValue(box_value(Visibility::Collapsed));
	this->NotEmptyValue(box_value(Visibility::Visible));
}