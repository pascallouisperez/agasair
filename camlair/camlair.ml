(* TODO: why isn't module Core around?
open Core.Std *)
open Base

module Altitude = struct
  (* The Altitude in feet, i.e.
   - 500ft is represented as 500
   - FL130 is represented as 13000. *)
  (* TODO: should really disallow valus above 10_000 from having any 100s -->
   maybe this should be an object instead, where ctor is fallible,
   or a private type which requires construction and returns `t option` *)
  type t = int
  [@@deriving compare, sexp];;
  let to_string (alt:t) : string =
    if alt < 10_000 then Printf.sprintf "%d" alt
    else Printf.sprintf "FL%d" (alt/100)
end

module Sky = struct
    type t =
        | Clear
        | Scattered
        | Broken of Altitude.t
        | Overcast of Altitude.t
    [@@deriving compare, sexp];;
    let to_string = function
        | Clear -> "clear"
        | Scattered -> "scattered"
        | Broken alt -> Printf.sprintf "broken(%d)" alt
        | Overcast alt -> Printf.sprintf "overcast(%d)" alt
  let parse (input:string) : t option =
    match String.sub input ~pos:0 ~len:3 with
    (* TODO: parse int --> convert to altitude *)
    | "OVC" -> Some (Overcast 3000)
    | "BKN" -> Some (Broken 3000)
    | _ -> None
end

module Metar = struct
    type t = {
        (* timestamp: Time.t; *)
        sky: Sky.t;
        temperature: int;
        dew_point: int;
    }
    [@@deriving compare, sexp];;
    let re_whitespace = Str.regexp "[ \n\r\x0c\t]+"
    let to_string (metar:t) : string =
        Sky.to_string metar.sky
    let parse (input:string) : t option =
      let input_split = Str.split re_whitespace input in
      (* TODO: why is printf not available here?
      let () = Printf.printf "%s\n" input_split[0] in *)
      match input_split with
      | ident :: time :: kind :: winds :: variable :: vis :: skycond :: _ -> 
        Option.bind (Sky.parse skycond) ~f:(fun sky ->
        Some {
          sky = sky;
          temperature = 0;
          dew_point = 0;
        })
      | _ -> None
end

let%test_unit "Sky.parse" =
  [%test_eq: Sky.t option]
    (Sky.parse "BKN049")
    (Some (Sky.Broken 4900))

let%test_unit "Metar.parse" =
  [%test_eq: Metar.t option]
    (Metar.parse "KHTO 271835Z AUTO 27013G23KT 250V310 10SM BKN049 08/M06 A2957 RMK AO2 T00771058")
    (Some {
      sky = Broken 4900;
      temperature = 8;
      dew_point = -6;
    })
