# Factura Electronica (C++)

This is a small C++ library that provides all the necesary logic and validation to create and publish electronic invoices following the requirements of the Ministry of Finance of Costa Rica for individuals and small bussiness (in the future will be expanded). Currently it follows the requirements [version 4.4](https://atv.hacienda.go.cr/ATV/ComprobanteElectronico/frmAnexosyEstructuras.aspx) 


## Requirements
- Windows 10+
- Visual Studio (>=2022)

In the future the supported systems will be expanded.

## Build
Because in the future I pretend to create an user interface and most of the end-users will run this on a Windows computer, you need Visual Studio (>=2022) to compile the code.

## Testing

The project uses [gtest](https://google.github.io/googletest/). Just go to the `Test Explorer` and run the tests.

## Roadmap

- [ ] Core Objects Logic
- [ ] XML Generation, Parsing and Signing
- [ ] Ministry of Hacienda API logic and connection
- [ ] PDF generation
- [ ] Email generation
- [ ] User Interface
- [ ] Support for Linux and Mac.
