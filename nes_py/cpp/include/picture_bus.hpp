#ifndef PICTUREBUS_H
#define PICTUREBUS_H
#include <vector>
#include "cartridge.hpp"
#include "mapper.hpp"

/// The bus for graphical data to travel along
class PictureBus {

private:
    /// the VRAM on the picture bus
    std::vector<uint8_t> m_RAM;
    /// indexes where they start in RAM vector
    std::size_t NameTable0, NameTable1, NameTable2, NameTable3;
    /// the palette for decoding RGB tuples
    std::vector<uint8_t> m_palette;
    /// a pointer to the mapper on the cartridge
    Mapper* m_mapper;

public:
    /// Initialize a new picture bus.
    PictureBus() : m_RAM(0x800), m_palette(0x20), m_mapper(nullptr) { };;

    /// Read a byte from an address on the VRAM.
    ///
    /// @param address the 16-bit address of the byte to read in the VRAM
    ///
    /// @return the byte located at the given address
    ///
    uint8_t read(Address address);

    /// Write a byte to an address in the VRAM.
    ///
    /// @param address the 16-bit address to write the byte to in VRAM
    /// @param value the byte to write to the given address
    ///
    void write(Address address, uint8_t value);

    /// Set the mapper pointer to a new value.
    ///
    /// @param mapper the new mapper pointer for the bus to use
    ///
    bool set_mapper(Mapper *mapper);

    /// Read a color index from the palette.
    ///
    /// @param address the address of the palette color
    ///
    /// @return the index of the RGB tuple in the color array
    ///
    uint8_t read_palette(uint8_t address) { return m_palette[address]; };

    /// Update the mirroring and name table from the mapper.
    void update_mirroring();

};

#endif // PICTUREBUS_H