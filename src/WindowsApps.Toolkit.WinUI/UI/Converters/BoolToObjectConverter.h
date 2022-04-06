#pragma once

#include "UI.Converters.BoolToObjectConverter.g.h"

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation
{
    using namespace winrt;
    using namespace winrt::Windows::Foundation;
    using namespace winrt::Windows::UI::Xaml::Interop;
    using namespace winrt::Microsoft::UI::Xaml;

    struct BoolToObjectConverter : BoolToObjectConverterT<BoolToObjectConverter>
    {
        BoolToObjectConverter() = default;

    public:
        static DependencyProperty TrueValueProperty();
        static DependencyProperty FalseValueProperty();

    public:
        IInspectable TrueValue();
        void TrueValue(IInspectable value);

        IInspectable FalseValue();
        void FalseValue(IInspectable value);

    public: //IValueConverter
        IInspectable Convert(IInspectable const& value, TypeName const& targetType, IInspectable const& parameter, hstring const& language);
        IInspectable ConvertBack(IInspectable const& value, TypeName const& targetType, IInspectable const& parameter, hstring const& language);
    

    private:
        static DependencyProperty __trueValueProperty;
        static DependencyProperty __falseValueProperty;

    };
}

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::factory_implementation
{
    struct BoolToObjectConverter : BoolToObjectConverterT<BoolToObjectConverter, implementation::BoolToObjectConverter>
    {
    };
}
