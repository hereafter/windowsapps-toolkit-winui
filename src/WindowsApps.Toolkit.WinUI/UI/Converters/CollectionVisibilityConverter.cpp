#include "pch.h"
#include "CollectionVisibilityConverter.h"
#if __has_include("UI.Converters.CollectionVisibilityConverter.g.cpp")
#include "UI.Converters.CollectionVisibilityConverter.g.cpp"
#endif

using namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation;


CollectionVisibilityConverter::CollectionVisibilityConverter()
{
	this->EmptyValue(box_value(Visibility::Collapsed));
	this->NotEmptyValue(box_value(Visibility::Visible));
}