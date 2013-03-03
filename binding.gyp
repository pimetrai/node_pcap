{
  "targets": [
    {
      "target_name": "pcap_binding",
      "sources": [
        "pcap_binding.cc"
      ],
      "link_settings": {
        "libraries": [
          "-lpcap"
        ]
      }
    },
    {
      "target_name": "socket_watcher_binding",
      "sources": [
        "socket_watcher_binding.cpp",
        "socket_watcher.cpp"
      ],

'configurations': {
        'Release': {
            'xcode_settings': { 'GCC_OPTIMIZATION_LEVEL': 3 }
          , 'cflags': [ '-O3' ]
          , 'ldflags': [ '-O3' ]
        }
      , 'Debug': {
            'xcode_settings': { 'GCC_OPTIMIZATION_LEVEL': 0 }
          , 'cflags': [ '-g', '-O0', ]
          , 'ldflags': [ '-g', '-O0' ]
        }
      , 'Coverage': {
            'xcode_settings': {
                'GCC_OPTIMIZATION_LEVEL': 0
              , 'OTHER_LDFLAGS': ['--coverage']
              , 'OTHER_CFLAGS':  ['--coverage']
            }
          , 'cflags': [ '-O0', '--coverage' ]
          , 'ldflags': [ '--coverage' ]
        }
      }
    


    }
  ]
}