/*--------------------------------------------------------------------------------------------------------------------*\
| Foobot - IEEE infrared protocol                                                                                      |
| Constructed from the template file ir_Template.cpp. It is fundamentally just the NEC format with significant parts   |
| of the protocol removed. In effect, it is a basic 8-N-1 format with the same timing and carrier as NEC protocol.     |
| Please refer to the rules if you wish to confirm the timing definitions included.                                    |
\*--------------------------------------------------------------------------------------------------------------------*/

#include "IRremote.h"
#include "IRremoteInt.h"

// -------------------- DEFINITIONS --------------------
#define IEEE_BITS          8  // Bits per TX

//All times below given in microseconds (us)
#define IEEE_HDR_MARK    9000 // Header mark length
#define IEEE_HDR_SPACE   4500 // Header space length

#define IEEE_BIT_MARK    560  // Bit mark length
#define IEEE_ONE_SPACE   1680 // Space for a logical 1
#define IEEE_ZERO_SPACE  560  // Space for a logical 0

// -------------------- TX FUNC --------------------
#if SEND_IEEE
void  IRsend::sendIEEE (unsigned long data,  int nbits)
{
	// Set IR carrier frequency
	enableIROut(38);

	// Header
	mark (IEEE_HDR_MARK);
	space(IEEE_HDR_SPACE);

	// Data
	for (unsigned long  mask = 1UL << (nbits - 1);  mask;  mask >>= 1) {
		if (data & mask) {
			mark (IEEE_BIT_MARK);
			space(IEEE_ONE_SPACE);
		} else {
			mark (IEEE_BIT_MARK);
			space(IEEE_ZERO_SPACE);
		}
	}

	// Footer
	mark(IEEE_BIT_MARK);
    space(0);  // Always end with the LED off
}
#endif

// -------------------- RX FUNC --------------------
#if DECODE_IEEE
bool  IRrecv::decodeIEEE (decode_results *results)
{
	unsigned long  data   = 0;  // Somewhere to build our code
	int            offset = 1;  // Skip the Gap reading

	// Check we have the right amount of data
	if (irparams.rawlen != 1 + 2 + (2 * IEEE_BITS) + 1)  return false ;

	// Check initial Mark+Space match
	if (!MATCH_MARK (results->rawbuf[offset++], IEEE_HDR_MARK ))  return false ;
	if (!MATCH_SPACE(results->rawbuf[offset++], IEEE_HDR_SPACE))  return false ;

	// Read the bits in
	for (int i = 0;  i < IEEE_BITS;  i++) {
		// Each bit looks like: MARK + SPACE_1 -> 1
		//                 or : MARK + SPACE_0 -> 0
		if (!MATCH_MARK(results->rawbuf[offset++], IEEE_BIT_MARK))  return false ;

		// IR data is big-endian, so we shuffle it in from the right:
		if      (MATCH_SPACE(results->rawbuf[offset], IEEE_ONE_SPACE))   data = (data << 1) | 1 ;
		else if (MATCH_SPACE(results->rawbuf[offset], IEEE_ZERO_SPACE))  data = (data << 1) | 0 ;
		else                                                        return false ;
		offset++;
	}

	// Success
	results->bits        = IEEE_BITS;
	results->value       = data;
	results->decode_type = IEEE;
	return true;
}
#endif