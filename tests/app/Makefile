BUILD_DIR = build
FIXTURES_DIR = dist
PROJECT = process_codesign_test_helper.xcodeproj
HELPER_A = $(BUILD_DIR)/a/process_codesign_test_helper.app
HELPER_B = $(BUILD_DIR)/b/process_codesign_test_helper.app
FIXTURE_A = $(FIXTURES_DIR)/process_codesign_test_helper_a.app
FIXTURE_B = $(FIXTURES_DIR)/process_codesign_test_helper_b.app

all:
	xcodegen generate
	xcodebuild \
		-project $(PROJECT) \
		-scheme process_codesign_test_helper_a \
		-configuration Release \
		-destination 'generic/platform=macOS' \
		-derivedDataPath $(CURDIR)/$(BUILD_DIR)/DerivedData/a \
		ARCHS='arm64 x86_64' \
		CONFIGURATION_BUILD_DIR=$(CURDIR)/$(BUILD_DIR)/a \
		build
	xcodebuild \
		-project $(PROJECT) \
		-scheme process_codesign_test_helper_b \
		-configuration Release \
		-destination 'generic/platform=macOS' \
		-derivedDataPath $(CURDIR)/$(BUILD_DIR)/DerivedData/b \
		ARCHS='arm64 x86_64' \
		CONFIGURATION_BUILD_DIR=$(CURDIR)/$(BUILD_DIR)/b \
		build

prepare-fixtures: all
	rm -rf $(FIXTURE_A)
	rm -rf $(FIXTURE_B)
	cp -R $(HELPER_A) $(FIXTURE_A)
	cp -R $(HELPER_B) $(FIXTURE_B)
	bash ../../scripts/codesign.sh $(FIXTURES_DIR)
	for f in $(FIXTURES_DIR)/*.app; do codesign -dvv $$f; echo; done

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(PROJECT)
