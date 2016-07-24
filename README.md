# Notes of Tutorial on Erasure Coding for Storage Applications

Storage relavated includes:
1. RAID-6: EVENODD, RDP, X-Code...(specialized XOR-based)
2. Non-MDS codes

## Erasure Coding Basics
**k** disks of data + **m** disks of parity = **n** total disks

**MDS**:reconstruct data from any m failures

**horizontal** code and **vertical** code:systematic

what is a **Stripe**
* Theoretical View: minimum collection of bits
* Systems View: minimum partitiion of systems
    balance load by rotating

## The Basics: Generator Matrices
(what we have: k data disks, n total disks, r rows of each)

Generator Matrix:
* nr rows, kr cols
* can do encoding and decoding as well

Data Disks:
* kr rows, 1 cols

Results:
* nr rows, 1 cols

Two Arithmetic:
1. XOR（only when w=1）
2. GF(2^w)

## Code1:Reed-Solomon Codes
## Code2:Cachy Reed-Solomon Codes
## Code3:Linux RAID-6
(detailed info to be added)

## Code4:EVENODD
Character:
* m=2
* k=prime(can be relaxed)
* r=k-1

## Code5:RDP(currently coding on)
Character:
* Row Diagonal Parity
* k+1=prime
* k=r
* get rid of **S** !!!
* seems to be a _improvement_ of EVENODD

## Code6:X-Code
## Codes7-9: Other Bit-Matrix Codes
