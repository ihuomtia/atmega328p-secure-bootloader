# SecureBootloader

SecureBootloader is an academic research project aimed at implementing a secure bootloader for the ATmega328P microcontroller. While the project ultimately exceeded the size limitations of the ATmega328P's bootloader section, it serves as a valuable learning resource and starting point for those interested in embedded systems security and bootloader design.

## Project Overview

The main goal of this project was to create a secure bootloader for the ATmega328P, incorporating encryption and authentication mechanisms. The project provides insights into the challenges and considerations involved in designing secure bootloaders for resource-constrained devices.

This project was a collaborative effort between [ihuomtia](https://github.com/ihuomtia) and [z4rr1t](https://github.com/z4rr1t) as part of an academic research initiative.

**Important Note:** This project is not production-ready and is no longer actively maintained. It is provided as-is for educational and research purposes only.

## Key Features

1. **Secure Bootloader Implementation**: An attempt to create a secure bootloader for ATmega328P.
2. **Encryption and Authentication**: Incorporation of security features using the ECC library (https://github.com/iSECPartners/nano-ecc).
3. **AVRBro Tool**: A custom tool similar to AVRDUDE, specifically designed for use with this bootloader.
4. **Firmware Verification**: Cryptographic techniques including digital signatures and hash calculations for firmware integrity and authenticity.
5. **Self-check Mechanisms**: Ensures the bootloader's own integrity against tampering or illegal changes.

## Project Outcomes

- **Secure Bootloader Size**: The final bootloader with encryption features was approximately 24,816 bytes.
- **Barebone Bootloader Size**: Without encryption features, the basic bootloader was about 524 bytes.
- **ATmega328P Limitations**: The maximum bootloader size for ATmega328P is 4,096 bytes (2,048 words, 32 pages) with BOOTSZ0=0 and BOOTSZ1=0 configuration.

## Limitations and Potential

While the current implementation exceeds the size limitations of the ATmega328P's bootloader section, it's important to note that this bootloader could potentially be used with other hardware platforms that don't have the same memory constraints as the ATmega328P. This opens up possibilities for applying this secure bootloader design to a wider range of microcontrollers and embedded systems with larger memory capacities.

For the ATmega328P specifically, this project serves as a valuable learning resource and starting point for further development and optimization. The concepts and security features implemented here could be adapted and optimized for use in more resource-constrained environments.

## AVRBro

AVRBro is a custom tool developed alongside the SecureBootloader. It's designed to interact with the bootloader, handling tasks such as firmware upload and verification. For more information, see `tools/avrbro.py`.

## Getting Started

To explore this project:

1. Clone the repository
2. Review the source code in the `src/` directory
3. Check out the AVRBro tool in `tools/avrbro.py`

## Building the Project

This project uses PlatformIO for build management. To build the project:

1. Install PlatformIO
2. Navigate to the project directory
3. Run `pio run`

Refer to `platformio.ini` for build configurations.

## Academic Research Conclusion

The creation of a secure bootloader for the ATmega328P microcontroller is a significant step towards improving the security and dependability of embedded systems. Key findings include:

- The bootloader provides strong defense against security risks such as malware injection, unauthorized code execution, and system compromise.
- Cryptographic techniques, including digital signatures and hash calculations, are used to verify firmware integrity and authenticity.
- Self-check mechanisms ensure the bootloader's own integrity.
- Despite size limitations on the ATmega328P, the secure bootloader offers a viable approach to secure firmware updates, helping organizations comply with industry standards and regulatory requirements.
- The project contributes to strengthening the security posture of microcontroller-based devices across various industries and applications.

## Contributing

While this project is no longer actively maintained, the repository remains open for educational purposes. Feel free to fork the project if you wish to build upon or modify it for your own research or learning.

## License

This project is open-source and available under the [MIT License](https://opensource.org/licenses/MIT).

## Acknowledgments

This project was created as an academic research project by [ihuomtia](https://github.com/ihuomtia) and [z4rr1t](https://github.com/z4rr1t). Special thanks to the developers of the nano-ecc library (https://github.com/iSECPartners/nano-ecc) which was instrumental in implementing the encryption features.

## Disclaimer

This project is not production-ready and is no longer maintained. While this bootloader exceeds the size limitations of the ATmega328P, it could potentially be used with other hardware platforms that have larger memory capacities. For the ATmega328P, this project serves as an educational resource and starting point for those interested in embedded security and bootloader design. Any practical implementation for resource-constrained devices would require significant optimization.