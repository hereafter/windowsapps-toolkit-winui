#include "pch.h"
#include "FileSizeToFriendlyStringConverter.h"
#if __has_include("UI.Converters.FileSizeToFriendlyStringConverter.g.cpp")
#include "UI.Converters.FileSizeToFriendlyStringConverter.g.cpp"
#endif

#include "ConverterTools.h"

using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::UI::Xaml::Interop;
using namespace winrt::Microsoft::UI::Xaml;

using namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation;
using namespace ::WindowsApps::Toolkit::WinUI::UI::Converters::Internals;



IInspectable FileSizeToFriendlyStringConverter::Convert(IInspectable const& value, TypeName const&, IInspectable const&, hstring const&)
{
	if (!value) return box_value(L"");

	auto n = ConverterTools::TryParseInt64(value);

	return box_value(ConverterTools::ToFileSizeString(n));
}

IInspectable FileSizeToFriendlyStringConverter::ConvertBack(IInspectable const&, TypeName const&, IInspectable const&, hstring const&)
{
	throw_hresult({ E_NOTIMPL });
}
