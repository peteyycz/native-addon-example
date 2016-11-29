{
  "targets": [
  {
    "conditions": [
      [ 'OS!="win"', {
        "cflags+": [ "-std=c++14" ],
        "cflags_c+": [ "-std=c++14" ],
        "cflags_cc+": [ "-std=c++14" ],
      }],
      [ 'OS=="mac"', {
        "xcode_settings": {
          "OTHER_CPLUSPLUSFLAGS" : [ "-std=c++14" ],
        },
      }],
    ],
    "include_dirs" : [
      "<!(node -e \"require('nan')\")"
    ],
    "target_name": "addon",
    "sources": [ "example.cc" ]
  }
  ]
}
