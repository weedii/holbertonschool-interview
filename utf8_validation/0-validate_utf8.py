#!/usr/bin/python3
"""
validUTF8
"""

def validUTF8(data):
    # number of bytes
    numBytes = 0
    
    mask1 = 1 << 7  # 128
    mask2 = 1 << 6  # 64
    
    for byte in data:
        # get the 8 least bits
        byte = byte & 255
        
        if numBytes == 0:
            # check how many bytes
            mask = 1 << 7
            while mask & byte:
                numBytes += 1
                mask = mask >> 1
            
            # check for 1 byte
            if numBytes == 0:
                continue  # its a 1 byte character ASCII
            if numBytes == 1 or numBytes > 4:
                return False  # invalid UTF-8
        else:
            # check that the byte starts with '10'
            if not (byte & mask1 and not (byte & mask2)):
                return False
        
        # Decrement for each byte
        numBytes -= 1
    
    return numBytes == 0
