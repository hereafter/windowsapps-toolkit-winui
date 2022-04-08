#pragma once

namespace WindowsApps { namespace  Toolkit {
namespace WinUI { namespace UI { 
namespace Converters { namespace Internals {

using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::UI::Xaml::Interop;

class ConverterTools
{
public:
	static bool TryParseBool(IInspectable const& parameter);
	static double TryParseDouble(IInspectable const& value);
	static IInspectable Convert(IInspectable const& value, TypeName const& targetType);
};

}}}}}};

