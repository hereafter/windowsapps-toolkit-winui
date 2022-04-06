#include "pch.h"
#include "ConvertersPage.xaml.h"
#if __has_include("ConvertersPage.g.cpp")
#include "ConvertersPage.g.cpp"
#endif

#include <winrt/WindowsApps_Toolkit_WinUI_Test.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters;
using namespace winrt::WindowsApps::Toolkit::WinUI::Extensions;
using namespace winrt::Microsoft::UI::Xaml::Data;
using namespace winrt::Windows::UI::Xaml::Interop;

using namespace winrt::WindowsApps::Toolkit::WinUI::Test::implementation;


ConvertersPage::ConvertersPage()
{
    InitializeComponent();
}


bool ConvertersPage::IsTestOn()
{
    return true;
}

hstring ConvertersPage::TestValue()
{
    return L"HELLO WORLD";
}


void ConvertersPage::OnButtonClick(IInspectable const&, RoutedEventArgs const&)
{
    myButton().Content(box_value(L"Clicked"));

    EmptyObjectToObjectConverter converter{};
    converter.EmptyValue(box_value(L"Collapsed"));
    converter.NotEmptyValue(box_value(L"Visible"));
    auto vc = converter.as<IValueConverter>();

    auto value = box_value(this->TestValue());
    auto targetType = xaml_typename<winrt::Microsoft::UI::Xaml::Visibility>();
    hstring language = L"";
    auto v=unbox_value<winrt::Microsoft::UI::Xaml::Visibility>(vc.Convert(value, targetType, nullptr, language));
}
