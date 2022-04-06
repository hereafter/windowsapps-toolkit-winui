#include "pch.h"
#include "ConvertersPage.xaml.h"
#if __has_include("ConvertersPage.g.cpp")
#include "ConvertersPage.g.cpp"
#endif

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

    this->TestBoolToObjectConverter();
}


void ConvertersPage::TestBoolToObjectConverter()
{
    auto&& convert = BoolToObjectConverter{};
    convert.TrueValue(box_value(Visibility::Visible));
    convert.FalseValue(box_value(Visibility::Collapsed));

    auto source = box_value(Visibility::Visible);
    hstring language{ L"" };
    auto value=convert.ConvertBack(source, xaml_typename<Microsoft::UI::Xaml::Visibility>(), nullptr, language);
}