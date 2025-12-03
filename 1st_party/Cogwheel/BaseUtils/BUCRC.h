#include <cstdint>

struct CRCEntry {
    uint32_t uiCRC;
    uint32_t uiID;
};

class BUCRCTable {
public:
    CRCEntry* mpEntries;
    uint16_t muiCount;
    uint16_t muiAllocCount;
    uint32_t muiFlags;
};