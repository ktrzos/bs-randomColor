open Jest;
open RandomColorRe;

let () =
  describe(
    "randomColor",
    ExpectJs.(
      () => {
        test("should generate color", () =>
          expect(randomColor()) |> not |> toBe("")
        );
        test("should generate other color everytime", () => {
          let value1 = randomColor();
          let value2 = randomColor();

          expect(value1) |> not |> toBe(value2);
        });
      }
    ),
  );

let () =
  describe(
    "randomColor seed",
    ExpectJs.(
      () => {
        test("should generate simple color for seed", () =>
          expect(randomColor(~seed="test", ())) |> toBe("#f9a05c")
        );
        test("should generate same color for identical seed", () => {
          let value1 = randomColor(~seed="test2", ());
          let value2 = randomColor(~seed="test2", ());

          expect(value1) |> toBe(value2);
        });
        test("should generate different color for different seed", () => {
          let value1 = randomColor(~seed="test3", ());
          let value2 = randomColor(~seed="test4", ());

          expect(value1) |> not |> toBe(value2);
        });
      }
    ),
  );

let () =
  describe(
    "randomColor format",
    ExpectJs.(
      () => {
        test("should generate color with default format", () => {
          let value1 = randomColor(~seed="test", ());
          let value2 = randomColor(~seed="test", ~format=FormatHex, ());

          expect(value1) |> toBe(value2);
        });
        test("should return proper color in HEX format", () =>
          expect(randomColor(~seed="test", ~format=FormatHex, ())) |> toBe("#f9a05c")
        );
        test("should return proper color in RGB format", () =>
          expect(randomColor(~seed="test", ~format=FormatRgb, ())) |> toBe("rgb(249, 160, 92)")
        );
        test("should return proper color in RGBa format", () =>
          expect(randomColor(~seed="test", ~format=FormatRgba, ()))
          |> toContainString("rgba(249, 160, 92, 0.")
        );
        test("should return proper color in HSL format", () =>
          expect(randomColor(~seed="test", ~format=FormatHsl, ()))
          |> toBe("hsl(26, 93.92%, 67.13%)")
        );
      }
    ),
  );

let () =
  describe(
    "randomColor format type as string",
    ExpectJs.(
      () => {
        test("should return rgb", () =>
          expect(formatToString(FormatRgb)) |> toBe("rgb")
        );
        test("should return rgba", () =>
          expect(formatToString(FormatRgba)) |> toBe("rgba")
        );
        test("should return hsl", () =>
          expect(formatToString(FormatHsl)) |> toBe("hsl")
        );
        test("should return hsla", () =>
          expect(formatToString(FormatHsla)) |> toBe("hsla")
        );
        test("should return hex", () =>
          expect(formatToString(FormatHex)) |> toBe("hex")
        );
      }
    ),
  );

let () =
  describe(
    "randomColor format array type as string",
    ExpectJs.(
      () => {
        test("should return rgbArray", () =>
          expect(formatArrayToString(FormatRgbArray)) |> toBe("rgbArray")
        );
        test("should return hslArray", () =>
          expect(formatArrayToString(FormatHslArray)) |> toBe("hslArray")
        );
      }
    ),
  );

let () =
  describe(
    "randomColor hue",
    ExpectJs.(
      () => {
        test("should return proper color for red hue", () =>
          expect(randomColor(~seed="test", ~hue=HueRed, ())) |> toBe("#f95c98")
        );
        test("should return proper color for orange hue", () =>
          expect(randomColor(~seed="test", ~hue=HueOrange, ())) |> toBe("#f9905c")
        );
        test("should return proper color for yellow hue", () =>
          expect(randomColor(~seed="test", ~hue=HueYellow, ())) |> toBe("#fcdc5d")
        );
        test("should return proper color for green hue", () =>
          expect(randomColor(~seed="test", ~hue=HueGreen, ())) |> toBe("#ddf95c")
        );
        test("should return proper color for blue hue", () =>
          expect(randomColor(~seed="test", ~hue=HueBlue, ())) |> toBe("#5becf7")
        );
        test("should return proper color for purple hue", () =>
          expect(randomColor(~seed="test", ~hue=HuePurple, ())) |> toBe("#8c5bf7")
        );
        test("should return proper color for pink hue", () =>
          expect(randomColor(~seed="test", ~hue=HuePink, ())) |> toBe("#d75dfc")
        );
        test("should return proper color for monochrome hue", () =>
          expect(randomColor(~seed="test", ~hue=HueMonochrome, ())) |> toBe("#303030")
        );
        test("should return proper color for monochrome hue", () =>
          expect(randomColor(~seed="test", ~hue=HueMonochrome, ~luminosity=LuminosityDark, ()))
          |> toBe("#070707")
        );
      }
    ),
  );

let () =
  describe(
    "randomColor hsl type as string",
    ExpectJs.(
      () => {
        test("should return red", () =>
          expect(hueToString(HueRed)) |> toBe("red")
        );
        test("should return orange", () =>
          expect(hueToString(HueOrange)) |> toBe("orange")
        );
        test("should return yellow", () =>
          expect(hueToString(HueYellow)) |> toBe("yellow")
        );
        test("should return green", () =>
          expect(hueToString(HueGreen)) |> toBe("green")
        );
        test("should return blue", () =>
          expect(hueToString(HueBlue)) |> toBe("blue")
        );
        test("should return purple", () =>
          expect(hueToString(HuePurple)) |> toBe("purple")
        );
        test("should return pink", () =>
          expect(hueToString(HuePink)) |> toBe("pink")
        );
        test("should return monochrome", () =>
          expect(hueToString(HueMonochrome)) |> toBe("monochrome")
        );
      }
    ),
  );

let () =
  describe(
    "randomColor luminosity",
    ExpectJs.(
      () => {
        test("should return proper color for bright luminosity", () =>
          expect(randomColor(~seed="test", ~luminosity=LuminosityBright, ())) |> toBe("#f9a05c")
        );
        test("should return proper color for light luminosity", () =>
          expect(randomColor(~seed="test", ~luminosity=LuminosityLight, ())) |> toBe("#fcd7ba")
        );
        test("should return proper color for dark hue", () =>
          expect(randomColor(~seed="test", ~luminosity=LuminosityDark, ())) |> toBe("#e06c14")
        );
      }
    ),
  );

let () =
  describe(
    "randomColor luminosity type as string",
    ExpectJs.(
      () => {
        test("should return bright", () =>
          expect(luminosityToString(LuminosityBright)) |> toBe("bright")
        );
        test("should return light", () =>
          expect(luminosityToString(LuminosityLight)) |> toBe("light")
        );
        test("should return dark", () =>
          expect(luminosityToString(LuminosityDark)) |> toBe("dark")
        );
      }
    ),
  );

let () =
  describe(
    "randomColor alpha",
    ExpectJs.(
      () => {
        test("should generate rgba color with alpha #1", () =>
          expect(randomColor(~seed="test", ~format=FormatRgba, ~alpha=0.2, ()))
          |> toBe("rgba(249, 160, 92, 0.2)")
        );
        test("should generate rgba color with alpha #2", () =>
          expect(randomColor(~seed="test", ~format=FormatRgba, ~alpha=1.0, ()))
          |> toBe("rgba(249, 160, 92, 1)")
        );
        test("should generate hsla color with alpha #1", () =>
          expect(randomColor(~seed="test", ~format=FormatHsla, ~alpha=0.2, ()))
          |> toBe("hsla(26, 93.92%, 67.13%, 0.2)")
        );
        test("should generate hsla color with alpha #2", () =>
          expect(randomColor(~seed="test", ~format=FormatHsla, ~alpha=1.0, ()))
          |> toBe("hsla(26, 93.92%, 67.13%, 1)")
        );
      }
    ),
  );

let () =
  describe(
    "randomColor multiple colors",
    ExpectJs.(
      () => {
        test("should generate 2 colors", () =>
          expect(randomColorMultiple(~count=2, ())) |> toHaveLength(2)
        );

        test("should generate 6 colors", () =>
          expect(randomColorMultiple(~count=6, ())) |> toHaveLength(6)
        );

        test("should generate 3 colors for seed", () => {
          let value = randomColorMultiple(~seed="test123", ~count=3, ());

          expect(value) |> toHaveLength(3);
        });

        test("should generate 3 colors in RGB format", () => {
          let value = randomColorMultiple(~seed="test123", ~count=3, ~format=FormatRgb, ());

          expect(value)
          |> toEqual([|"rgb(231, 244, 83)", "rgb(76, 219, 186)", "rgb(249, 89, 196)"|]);
        });
      }
    ),
  );

let () =
  describe(
    "randomColor RGB result as array",
    ExpectJs.(
      () => {
        test("should generate rgb format as an array #1", () => {
          let (r, g, b) = randomColorRgbArray(~seed="word", ());

          expect((r, g, b)) |> toEqual((193, 81, 21));
        });

        test("should generate rgb format as an array #2", () => {
          let (r, g, b) = randomColorRgbArray(~seed="test2", ());

          expect((r, g, b)) |> toEqual((178, 232, 30));
        });

        test("should generate rgb array with hue", () => {
          let (r, g, b) = randomColorRgbArray(~seed="test", ~hue=HueRed, ());

          expect((r, g, b)) |> toEqual((137, 4, 48));
        });
      }
    ),
  );

let () =
  describe(
    "randomColor HSL result as array",
    ExpectJs.(
      () => {
        test("should generate hsl format as an array #1", () => {
          let (h, s, l) = randomColorHslArray(~seed="test1", ());

          expect((h, s, l)) |> toEqual((55, 92.31, 46.800000000000004));
        });

        test("should generate hsl format as an array #2", () => {
          let (h, s, l) = randomColorHslArray(~seed="test2", ());

          expect((h, s, l)) |> toEqual((76, 81.48, 51.415));
        });

        test("should generate rgb array with hue", () => {
          let (h, s, l) = randomColorHslArray(~seed="test", ~hue=HueGreen, ());

          expect((h, s, l)) |> toEqual((81, 94.17, 23.69));
        });
      }
    ),
  );
