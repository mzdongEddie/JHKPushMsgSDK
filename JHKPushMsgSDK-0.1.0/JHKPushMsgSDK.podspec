Pod::Spec.new do |s|
  s.name = "JHKPushMsgSDK"
  s.version = "0.1.0"
  s.summary = "\u{963f}\u{91cc}\u{4e91}\u{79fb}\u{52a8}\u{63a8}\u{9001}\u{96c6}\u{6210}"
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"mzdongEddie"=>"mazhendong@hisense.com"}
  s.homepage = "https://github.com/mzdongEddie/JHKPushMsgSDK"
  s.description = "TODO: Add long description of the pod here."
  s.source = { :path => '.' }

  s.ios.deployment_target    = '8.0'
  s.ios.vendored_framework   = 'ios/JHKPushMsgSDK.framework'
end
