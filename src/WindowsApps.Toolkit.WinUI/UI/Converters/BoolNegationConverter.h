﻿#pragma once

#include "UI.Converters.BoolNegationConverter.g.h"

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation
{
    using namespace winrt;
    using namespace winrt::Windows::Foundation;
    using namespace winrt::Windows::UI::Xaml::Interop;
    using namespace winrt::Microsoft::UI::Xaml;

    struct BoolNegationConverter : BoolNegationConverterT<BoolNegationConverter>
    {
        BoolNegationConverter() = default;

    public: //IValueConverter
        IInspectable Convert(IInspectable const& value, TypeName const&, IInspectable const&, hstring const&);
        IInspectable ConvertBack(IInspectable const& value, TypeName const&, IInspectable const&, hstring const&);
    };
}

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::factory_implementation
{
    struct BoolNegationConverter : BoolNegationConverterT<BoolNegationConverter, implementation::BoolNegationConverter>
    {
    };
}
