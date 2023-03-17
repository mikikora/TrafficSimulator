#pragma once

namespace TS::core::MO
{
class IVehicle
{
public:
    virtual std::string classname() const = 0;
    virtual ~IVehicle() = default;
};

} // namespace TS::core::MO
