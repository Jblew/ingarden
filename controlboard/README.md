# Programming BluePill F103C8 with ST-link V2 and platformio

Platformio settings:

```ini
[env:bluepill_stlink]
platform = ststm32
board = bluepill_f103c8
framework = arduino
debug_tool = stlink
upload_protocol = stlink
```

Hardware connections:
1. St-link V2 clone
2. 3V3->3V3, GND->GND, SWCLK->SWCLK, SWDIO->SWDIO. No other connections. USB not necessarily connected

To remove bootloader: (may be required to program with st-link)
1. Switch BOOT0 jumper to 1 (the higher one, meaning further from reset button)
2. Upload code from platformio
3. Switch BOOT0 jumper to 0
4. Upload again (and now programming with stlink should just work)