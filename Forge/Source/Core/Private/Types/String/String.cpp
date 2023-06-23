#include "Core/Public/Types/String/String.h"

namespace Forge {
	namespace Common
	{
		String::String(Void)
			: AbstractString(0, ~((Size)0))
		{
			this->m_data = TMemoryRegion<Char>();
		}
		String::String(Char ch, Size count)
			: AbstractString(count, ~((Size)0))
		{
			this->m_data = TMemoryRegion<Char>(new Char[this->m_count], this->m_count);

			Memory::MemorySet(
				this->m_data.GetPointer(), 
				ch, 
				this->m_data.GetCapacityBytes()
			);
		}
		String::String(ConstCharPtr string, Size count)
			: AbstractString(count, ~((Size)0))
		{
			this->m_data = TMemoryRegion<Char>(new Char[this->m_count], this->m_count);

			Memory::MemoryCopy(
				this->m_data.GetPointer(),
				const_cast<VoidPtr>(static_cast<ConstVoidPtr>(string)),
				this->m_data.GetCapacityBytes()
			);
		}
		String::String(ConstSelfTypeRef string, Size startIndex, Size endIndex)
			: AbstractString(endIndex - startIndex + 1, ~((Size)0))
		{
			this->m_data = TMemoryRegion<Char>(new Char[this->m_count], this->m_count);

			Memory::MemoryCopy(
				this->m_data.GetPointer(),
				const_cast<VoidPtr>(static_cast<ConstVoidPtr>(string.GetRawData() + startIndex)),
				this->m_data.GetCapacityBytes()
			);
		}

		String::String(SelfTypeMoveRef other)
			: AbstractString(0, ~((Size)0))
		{
			*this = Algorithm::Move(other);
		}
		String::String(ConstSelfTypeRef other)
			: AbstractString(0, ~((Size)0))
		{
			*this = other;
		}

		String::~String(Void)
		{
			this->m_data.Reset();
		}

		String::SelfTypeRef String::operator =(ConstChar ch)
		{
			this->Assign(ch, 1);

			return *this;
		}
		String::SelfTypeRef String::operator =(ConstCharPtr string)
		{
			this->Assign(string, Algorithm::GetStringLength(string));

			return *this;
		}
		String::SelfTypeRef String::operator =(SelfTypeMoveRef other)
		{
			this->m_data = Algorithm::Move(other.m_data);
			this->m_count = Algorithm::Move(other.m_count);

			return *this;
		}
		String::SelfTypeRef String::operator =(ConstSelfTypeRef other)
		{
			this->Assign(other, other.GetCount());

			return *this;
		}

		String::SelfType String::operator +(ConstChar ch)
		{
			String result = *this;

			result.Append(ch, 1);

			return result;
		}
		String::SelfType String::operator +(ConstCharPtr string)
		{
			String result = *this;

			result.Append(string, Algorithm::GetStringLength(string));

			return result;
		}
		String::SelfType String::operator +(ConstSelfTypeRef other)
		{
			String result = *this;

			result.Append(other, other.GetCount());

			return result;
		}

		String::SelfTypeRef String::operator +=(ConstChar ch)
		{
			this->Append(ch, 1);

			return *this;
		}
		String::SelfTypeRef String::operator +=(ConstCharPtr string)
		{
			this->Append(string, Algorithm::GetStringLength(string));

			return *this;
		}
		String::SelfTypeRef String::operator +=(ConstSelfTypeRef other)
		{
			this->Append(other, other.GetCount());

			return *this;
		}

		ConstCharPtr String::GetRawData(Void) const
		{
			return this->m_data.GetConstPointer();
		}

		Void String::ReserveCapacity(Size capacity)
		{
			if (this->m_data.GetCapacity() >= capacity)
				return;

			Size new_capacity;

			TMemoryRegion<Char> old_string_data = Algorithm::Move(this->m_data);

			new_capacity = old_string_data.GetCapacity() + (old_string_data.GetCapacity() / 2);
			new_capacity = new_capacity > capacity ? new_capacity : capacity;
			new_capacity = new_capacity < this->m_max_capacity ? new_capacity : this->m_max_capacity;
			new_capacity = (new_capacity + (4 - 1)) & ~(4 - 1);

			this->m_data = TMemoryRegion<Char>(new Char[new_capacity], new_capacity);

			Memory::MemorySet(this->m_data.GetPointer(), 0, this->m_data.GetCapacity());
			Memory::MemoryCopy(this->m_data.GetPointer(), old_string_data.GetPointer(), old_string_data.GetCapacity());

			old_string_data.Reset();
		}

		Void String::Assign(ConstChar ch, Size count)
		{
			if (this->m_data.GetCapacity() != count && count >= 1)
			{
				if (this->m_data.IsValid())
					this->m_data.Reset();

				this->m_data = TMemoryRegion<Char>(new Char[count], count);
			}

			this->m_count = count;

			Memory::MemorySet(
				this->m_data.GetPointer(), 
				ch, 
				this->m_data.GetCapacityBytes()
			);
		}
		Void String::Assign(ConstCharPtr string, Size count)
		{
			if (this->m_data.GetCapacity() != count && count >= 1)
			{
				if (this->m_data.IsValid())
					this->m_data.Reset();

				this->m_data = TMemoryRegion<Char>(new Char[count], count);
			}

			this->m_count = count;

			Memory::MemoryCopy(
				this->m_data.GetPointer(),
				const_cast<VoidPtr>(static_cast<ConstVoidPtr>(string)),
				this->m_data.GetCapacityBytes()
			);
		}
		Void String::Assign(ConstSelfTypeRef other, Size count)
		{
			if (this->m_data.GetCapacity() != count && count >= 1)
			{
				if (this->m_data.IsValid())
					this->m_data.Reset();

				this->m_data = TMemoryRegion<Char>(new Char[count], count);
			}

			this->m_count = count;

			Memory::MemoryCopy(
				this->m_data.GetPointer(),
				const_cast<VoidPtr>(static_cast<ConstVoidPtr>(other.GetRawData())),
				this->m_data.GetCapacityBytes()
			);
		}

		Void String::Append(ConstChar ch, Size count)
		{
			this->ReserveCapacity(this->m_count + count);

			Memory::MemorySet(this->m_data.GetPointer() + this->m_count, ch, count);

			this->m_count += count;
		}
		Void String::Append(ConstCharPtr string, Size count)
		{
			this->ReserveCapacity(this->m_count + count);

			Memory::MemoryCopy(
				this->m_data.GetPointer() + this->m_count,
				const_cast<VoidPtr>(static_cast<ConstVoidPtr>(string)),
				count
			);

			this->m_count += count;
		}
		Void String::Append(ConstSelfTypeRef other, Size count)
		{
			this->ReserveCapacity(this->m_count + other.GetCount());

			Memory::MemoryCopy(
				this->m_data.GetPointer() + this->m_count,
				const_cast<VoidPtr>(static_cast<ConstVoidPtr>(other.GetRawData())),
				other.GetCount()
			);

			this->m_count += other.GetCount();
		}

		Void String::Insert(Size offset, ConstChar ch, Size count)
		{
			this->ReserveCapacity(this->m_count + count);

			Size chs_to_shift = this->m_count - offset;

			for (I32 i = chs_to_shift; i >= offset; i--)
			{
				if (i < 0)
					break;

				this->m_data[i + count] = this->m_data[i];
			}

			Memory::MemorySet(
				this->m_data.GetPointer() + offset, 
				ch, 
				count
			);

			this->m_count += count;
		}
		Void String::Insert(Size offset, ConstCharPtr string, Size count)
		{
			this->ReserveCapacity(this->m_count + count);

			Size chs_to_shift = this->m_count - offset;

			for (I32 i = chs_to_shift; i >= offset; i--)
			{
				if (i < 0)
					break;

				this->m_data[i + count] = this->m_data[i];
			}

			Memory::MemoryCopy(
				this->m_data.GetPointer() + offset,
				const_cast<VoidPtr>(static_cast<ConstVoidPtr>(string)),
				count
			);

			this->m_count += count;
		}
		Void String::Insert(Size offset, ConstSelfTypeRef other, Size count)
		{
			this->ReserveCapacity(this->m_count + other.GetCount());

			Size chs_to_shift = this->m_count - offset;

			for (I32 i = chs_to_shift; i >= offset; i--)
			{
				if (i < 0)
					break;

				this->m_data[i + count] = this->m_data[i];
			}

			Memory::MemoryCopy(
				this->m_data.GetPointer() + offset,
				const_cast<VoidPtr>(static_cast<ConstVoidPtr>(other.GetRawData())),
				count
			);

			this->m_count += count;
		}

		Void String::Remove(Size offset)
		{
			this->Remove(offset, 1);
		}
		Void String::Remove(Size offset, Size count)
		{
			I32 chs_to_shift = this->m_count - count - offset;

			for (I32 i = offset + count; i < chs_to_shift; i++)
				this->m_data[i - count] = this->m_data[i];

			this->m_count -= count;
		}

		Void String::Clear(Void)
		{
			this->m_count = 0;

			Memory::MemorySet(
				this->m_data.GetPointer(), 
				0, 
				this->m_data.GetCapacityBytes()
			);
		}
	}
}