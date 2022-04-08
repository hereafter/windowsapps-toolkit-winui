#include "pch.h"
#include "StringFormatConverter.h"
#if __has_include("UI.Converters.StringFormatConverter.g.cpp")
#include "UI.Converters.StringFormatConverter.g.cpp"
#endif

#include <format>

using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::UI::Xaml::Interop;
using namespace winrt::Microsoft::UI::Xaml;
using namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation;


IInspectable StringFormatConverter::Convert(IInspectable const& value, TypeName const& targetType, IInspectable const& parameter, hstring const& language)
{	
	return nullptr;
}

IInspectable StringFormatConverter::ConvertBack(IInspectable const& value, TypeName const& targetType, IInspectable const& parameter, hstring const& language)
{
	throw_hresult({ E_NOTIMPL });
}