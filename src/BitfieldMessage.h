/* <!-- copyright */
/*
 * aria2 - a simple utility for downloading files faster
 *
 * Copyright (C) 2006 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
/* copyright --> */
#ifndef _D_BITFIELD_MESSAGE_H_
#define _D_BITFIELD_MESSAGE_H_

#include "PeerMessage.h"

class BitfieldMessage : public PeerMessage {
private:
  unsigned char* bitfield;
  int bitfieldLength;
  // for check
  int pieces;
public:
  BitfieldMessage():PeerMessage(),
		    bitfield(NULL), bitfieldLength(0),
		    pieces(0) {}

  virtual ~BitfieldMessage() {
    if(bitfield != NULL) {
      delete [] bitfield;
    }
  }

  enum ID {
    ID = 5
  };

  void setBitfield(const unsigned char* bitfield, int bitfieldLength);
  const unsigned char* getBitfield() const { return bitfield; }

  int getBitfieldLength() const { return bitfieldLength; }

  void setPieces(int pieces) {
    this->pieces = pieces;
  }
  int getPieces() const { return pieces;}

  virtual int getId() const { return ID; }
  virtual void receivedAction();
  virtual void send();
  virtual void check() const;
  virtual string toString() const;
};

#endif // _D_BITFIELD_MESSAGE_H_
