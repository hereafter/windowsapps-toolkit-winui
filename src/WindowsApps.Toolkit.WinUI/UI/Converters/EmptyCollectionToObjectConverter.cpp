#include "pch.h"
#include "EmptyCollectionToObjectConverter.h"
#if __has_include("UI.Converters.EmptyCollectionToObjectConverter.g.cpp")
#include "UI.Converters.EmptyCollectionToObjectConverter.g.cpp"
#endif

using namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation;

bool EmptyCollectionToObjectConverter::CheckValueIsEmpty(IInspectable value)
{
	if (!value) return true;

	auto pv = value.try_as<IPropertyValue>();
	if (!pv) return true;
	auto type = pv.Type();

	try {

		//TODO: any better template?
		switch (type)
		{
			case PropertyType::BooleanArray:
			{
				com_array<bool> data;
				pv.GetBooleanArray(data);
				return !data.empty();
			}
			case PropertyType::Char16Array:
			{
				com_array<char16_t> data;
				pv.GetChar16Array(data);
				return !data.empty();
			}
			case PropertyType::DateTimeArray:
			{
				com_array<DateTime> data;
				pv.GetDateTimeArray(data);
				return !data.empty();
			}
			case PropertyType::DoubleArray:
			{
				com_array<double> data;
				pv.GetDoubleArray(data);
				return !data.empty();
			}
			case PropertyType::GuidArray:
			{
				com_array<guid> data;
				pv.GetGuidArray(data);
				return !data.empty();
			}
			case PropertyType::InspectableArray:
			{
				com_array<IInspectable> data;
				pv.GetInspectableArray(data);
				return !data.empty();
			}
			case PropertyType::Int16Array:
			{
				com_array<int16_t> data;
				pv.GetInt16Array(data);
				return !data.empty();
			}
			case PropertyType::Int32Array:
			{
				com_array<int32_t> data;
				pv.GetInt32Array(data);
				return !data.empty();
			}
			case PropertyType::Int64Array:
			{
				com_array<int64_t> data;
				pv.GetInt64Array(data);
				return !data.empty();
			}
			case PropertyType::PointArray:
			{
				com_array<Point> data;
				pv.GetPointArray(data);
				return !data.empty();
			}
			case PropertyType::RectArray:
			{
				com_array<Rect> data;
				pv.GetRectArray(data);
				return !data.empty();
			}
			case PropertyType::SingleArray:
			{
				com_array<float> data;
				pv.GetSingleArray(data);
				return !data.empty();
			}
			case PropertyType::StringArray:
			{
				com_array<hstring> data;
				pv.GetStringArray(data);
				return !data.empty();
			}
			case PropertyType::SizeArray:
			{
				com_array<Size> data;
				pv.GetSizeArray(data);
				return !data.empty();
			}
			case PropertyType::TimeSpanArray:
			{
				com_array<TimeSpan> data;
				pv.GetTimeSpanArray(data);
				return !data.empty();
			}
			case PropertyType::UInt16Array :
			{
				com_array<uint16_t> data;
				pv.GetUInt16Array(data);
				return !data.empty();
			}
			case PropertyType::UInt32Array:
			{
				com_array<uint32_t> data;
				pv.GetUInt32Array(data);
				return !data.empty();
			}
			case PropertyType::UInt64Array:
			{
				com_array<uint64_t> data;
				pv.GetUInt64Array(data);
				return !data.empty();
			}
			case PropertyType::UInt8Array:
			{
				com_array<uint8_t> data;
				pv.GetUInt8Array(data);
				return !data.empty();
			}
		}
	}
	catch (...) {}

	return true;
}