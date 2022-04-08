#include "pch.h"
#include "ColorToDisplayNameConverter.h"
#if __has_include("UI.Converters.ColorToDisplayNameConverter.g.cpp")
#include "UI.Converters.ColorToDisplayNameConverter.g.cpp"
#endif

using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::UI;
using namespace winrt::Windows::UI::Xaml::Interop;
using namespace winrt::Microsoft::UI::Xaml;
using namespace winrt::Microsoft::UI::Xaml::Media;

using namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation;


IInspectable ColorToDisplayNameConverter::Convert(IInspectable const& value, TypeName const&, IInspectable const&, hstring const&)
{
	if (!value) return DependencyProperty::UnsetValue();

	auto color = value.try_as<Color>();
	if (!color)
	{
		auto brush = value.try_as<SolidColorBrush>();
		if (brush)
		{
			color = brush.Color();
		}
	}

	if (!color) return DependencyProperty::UnsetValue();
	return box_value(ColorHelper::ToDisplayName(color.value()));
}

IInspectable ColorToDisplayNameConverter::ConvertBack(IInspectable const&, TypeName const&, IInspectable const&, hstring const&)
{
	return DependencyProperty::UnsetValue();
}
