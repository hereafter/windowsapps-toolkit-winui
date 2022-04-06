#pragma once

#include "UI.Converters.EmptyObjectToObjectConverter.g.h"

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation
{
    using namespace winrt;
    using namespace winrt::Windows::Foundation;
    using namespace winrt::Windows::UI::Xaml::Interop;
    using namespace winrt::Microsoft::UI::Xaml;

    struct EmptyObjectToObjectConverter : EmptyObjectToObjectConverterT<EmptyObjectToObjectConverter>
    {
        EmptyObjectToObjectConverter() = default;

    public:
        static DependencyProperty EmptyValueProperty();
        static DependencyProperty NotEmptyValueProperty();    

    public:
        IInspectable EmptyValue();
        void EmptyValue(IInspectable value);

        IInspectable NotEmptyValue();
        void NotEmptyValue(IInspectable value);

    public: //IValueConverter
        IInspectable Convert(IInspectable const& value, TypeName const& targetType, IInspectable const& parameter, hstring const& language);
        IInspectable ConvertBack(IInspectable const& value, TypeName const& targetType, IInspectable const& parameter, hstring const& language);

    public:
        virtual bool CheckValueIsEmpty(IInspectable value);
        

    private:
        static DependencyProperty __emptyValueProperty;
        static DependencyProperty __notEmptyValueProperty;

    };
}

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::factory_implementation
{
    struct EmptyObjectToObjectConverter : EmptyObjectToObjectConverterT<EmptyObjectToObjectConverter, implementation::EmptyObjectToObjectConverter>
    {
    };
}
