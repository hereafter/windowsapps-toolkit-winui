#pragma once

#include "UI.Converters.DoubleToObjectConverter.g.h"

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation
{
    using namespace winrt;
    using namespace winrt::Windows::Foundation;
    using namespace winrt::Windows::UI::Xaml::Interop;
    using namespace winrt::Microsoft::UI::Xaml;

    struct DoubleToObjectConverter : DoubleToObjectConverterT<DoubleToObjectConverter>
    {
        DoubleToObjectConverter() = default;

    public:
        static DependencyProperty TrueValueProperty();
        static DependencyProperty FalseValueProperty();
        static DependencyProperty NullValueProperty();

        static DependencyProperty GreaterThanProperty();
        static DependencyProperty LessThanProperty();

    public:
        IInspectable TrueValue();
        void TrueValue(IInspectable const& value);
        IInspectable FalseValue();
        void FalseValue(IInspectable const& value);
        IInspectable NullValue();
        void NullValue(IInspectable const& value);

        double GreaterThan();
        void GreaterThan(double value);
        double LessThan();
        void LessThan(double value);


    public: //IValueConverter
        IInspectable Convert(IInspectable const& value, TypeName const& targetType, IInspectable const& parameter, hstring const& language);
        IInspectable ConvertBack(IInspectable const& value, TypeName const& targetType, IInspectable const& parameter, hstring const& language);


    private:
        static DependencyProperty __trueValueProperty;
        static DependencyProperty __falseValueProperty;
        static DependencyProperty __nullValueProperty;

        static DependencyProperty __greaterThanProperty;
        static DependencyProperty __lessThanProperty;

    };
}

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::factory_implementation
{
    struct DoubleToObjectConverter : DoubleToObjectConverterT<DoubleToObjectConverter, implementation::DoubleToObjectConverter>
    {
    };
}
