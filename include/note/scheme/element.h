#pragma once

namespace Notes::Scheme
{

struct Element
{
    enum class Necesserity
    {
        Optional = 0,
        Mandatory
    };

    Element(Necesserity necesserity);
    Necesserity getNecesserity() const noexcept;

private:
    Necesserity m_necesserity;
};

} // namespace Notes::Scheme
