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

	//TODO: template with std::enable_if ???
	static double TryParseDouble(IInspectable const& value);
	static int64_t TryParseInt64(IInspectable const& value);


	static IInspectable Convert(IInspectable const& value, TypeName const& targetType);

	static hstring ToFileSizeString(int64_t size);
};

}}}}}};

