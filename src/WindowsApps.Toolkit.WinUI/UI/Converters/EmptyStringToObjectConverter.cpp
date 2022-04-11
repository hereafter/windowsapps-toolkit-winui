#include "pch.h"
#include "EmptyStringToObjectConverter.h"
#if __has_include("UI.Converters.EmptyStringToObjectConverter.g.cpp")
#include "UI.Converters.EmptyStringToObjectConverter.g.cpp"
#endif

using namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation;


bool EmptyStringToObjectConverter::CheckValueIsEmpty(IInspectable value)
{
	return !value && unbox_value_or<hstring>(value, L"").empty();
}