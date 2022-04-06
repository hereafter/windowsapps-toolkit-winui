#include "pch.h"
#include "BoolNegationConverter.h"
#if __has_include("UI.Converters.BoolNegationConverter.g.cpp")
#include "UI.Converters.BoolNegationConverter.g.cpp"
#endif

using namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation;

using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::UI::Xaml::Interop;
using namespace winrt::Microsoft::UI::Xaml;

IInspectable BoolNegationConverter::Convert(IInspectable const& value, TypeName const&, IInspectable const&, hstring const&)
{
	return box_value(unbox_value_or<bool>(value, false));
}


IInspectable BoolNegationConverter::ConvertBack(IInspectable const& value, TypeName const&, IInspectable const&, hstring const&)
{
	return box_value(unbox_value_or<bool>(value, false));
}