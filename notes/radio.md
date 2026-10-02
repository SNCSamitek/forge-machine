# How to bind to bind an RP3 to an TX16S MkII

1. Make sure that you have the external Radiomaster Ranger Micro plugged into the controller
2. Open Radio Settings -> Hardware -> Internal RF: Turn it OFF
3. Create a new model (or reuse one).
4. Model settings -> Model Setup -> Internal RF (OFF) + External RF (CRSF)
5. Unplug the RP3 3 times until it double binlks.
6. Radio Settings -> Tools -> ExpressLRS -> Bind
7. RP3 light should be solid

# How to put RP3 antenna in inverted SBUS

1. Power cycle the RP3 antenna 3 times.
2. Wait 60 seconds for the antenna to flash rapidly and enter wifi mode.
3. Connect to the ExpressLRS_RX_XXXX wifi network using password `expresslrs`
4. Model -> Protocol -> Inverted SBUS

# How to receive data from RP3 antenna

1. Make sure your are bound and that the RP3 light is solid.
2. Make sure that the RP3 antenna is in inverted SBUS.
3. Read the data using sbus library.

### Resouces

- [RP3 Quick Start](./resources/RP3_Quick_Start_Guide.pdf)
- [TX16S MKII Guide](TX16SMKII_2.0.pdf)
