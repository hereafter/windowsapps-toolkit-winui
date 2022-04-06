#pragma once

#include "Extensions.StringExtensions.g.h"
#include <winrt/Windows.UI.h>

namespace winrt::WindowsApps::Toolkit::WinUI::Extensions::implementation
{
    using namespace winrt;
    using namespace winrt::Microsoft::UI;
    using namespace winrt::Microsoft::UI::Xaml;
    using namespace winrt::Windows::ApplicationModel::Resources;


    struct StringExtensions : StringExtensionsT<StringExtensions>
    {
        StringExtensions() = delete;

    public:
        static hstring GetLocalized(hstring const& resourceKey);
        static hstring GetLocalized(hstring const& resourceKey, Windows::UI::UIContext uiContext);
        static hstring GetLocalized(hstring const& resourceKey, hstring const& resourcePath);


    private:
        static ResourceLoader& IndependentLoader();

    private:
        static ResourceLoader __independentLoader;
    };
}



namespace winrt::WindowsApps::Toolkit::WinUI::Extensions::factory_implementation
{
    struct StringExtensions : StringExtensionsT<StringExtensions, implementation::StringExtensions>
    {
    };
}
