Pod::Spec.new do |spec|
  spec.name         = 'HyphenateFull-SDK'
  spec.version      = '3.1.2'
  spec.license 	    = { :type => 'MIT', :file => 'LICENSE' }
  spec.summary      = 'An Objective-C client for IM service'
  spec.homepage     = 'https://github.com/HyphenateInc/hyphenate-full-cocoapods'
  spec.author       = {'Hyphenate Inc.' => 'admin@easemob.com'}
  spec.source       =  {:git => 'https://github.com/lizilong1989/hyphenate-full-cocoapods-1.git', :tag => spec.version.to_s }
  spec.source_files = "HyphenateFullSDK/**/*.{h}"
  spec.platform     = :ios, '6.0'
  spec.requires_arc = true
  spec.frameworks   = 'CoreMedia', 'AudioToolbox', 'AVFoundation', 'ImageIO', 'MobileCoreServices',  'SystemConfiguration'
  spec.libraries    = 'iconv', 'c++', 'z', 'resolv', 'sqlite3', 'stdc++.6.0.9'
  spec.vendored_libraries = ['HyphenateFullSDK/lib/libHyphenateFullSDK_i386.a','HyphenateFullSDK/lib/libHyphenateFullSDK_x86_64.a','HyphenateFullSDK/lib/libHyphenateFullSDK_arm64.a','HyphenateFullSDK/lib/libHyphenateFullSDK_armv7.a','HyphenateFullSDK/lib/libHyphenateFullSDK_armv7s.a']
  spec.xcconfig     = {'OTHER_LDFLAGS' => '-ObjC'}
end
