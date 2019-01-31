# Contributing

## Code style
Based on Yuzu's style-guide.

### General Rules
* Use namespaces often

### Naming Rules
* Functions: `PascalCase`
* Variables: `lower_case_underscored`. Prefix with `g_` if global.
* Classes: `PascalCase`
* Files and Directories: `lower_case_underscored`
* Namespaces: `PascalCase`.

### Indentation/Whitespace Style
Follow the indentation/whitespace style shown below. Do not use tabs, use 4-spaces instead.

### Comments
* For regular comments, use C++ style (`//`) comments, even for multi-line ones.
* For doc-comments (Doxygen comments), use `/// ` if it's a single line, else use the `/**` `*/` style featured in the example. Start the text on the second line, not the first containing `/**`.
* For items that are both defined and declared in two separate files, put the doc-comment only next to the associated declaration. (In a header file, usually.) Otherwise, put it next to the implementation. Never duplicate doc-comments in both places.

```cpp
// Includes should be sorted lexicographically
// STD includes first, then, library includes, and finally project includes
// No blank line between #includes (unless conditional #include presents)
#include <map>
#include <memory>
#include <nihstro/shared_binary.h>
#include "common/math_util.h"
#include "common/vector_math.h"
#include "video_core/pica.h"
#include "video_core/video_core.h"

namespace Example {
    // Namespace contents are indented

    // Declare globals at the top
    int g_foo{};            // {} can be used to initialize types as 0, false, or nullptr
    char* g_some_pointer{}; // Pointer * and reference & stick to the type name, and make sure to
                            // initialize as nullptr!

    /// A colorful enum.
    enum SomeEnum {
        ColorRed,   ///< The color of fire.
        ColorGreen, ///< The color of grass.
        ColorBlue,  ///< Not actually the color of water.
    };

    /**
     * Very important struct that does a lot of stuff.
     * Note that the asterisks are indented by one space to align to the first line.
     */
    struct typedef {
        int x{}, y{}; // Always intitialize member variables!
    } Position;

    // Use "typename" rather than "class" here
    void FooBar() {
        if (note == the_space_after_the_if) {
            CallAfunction();
        } else {
            // Use a space after the // when commenting
        }

        // Place a single space after the for loop semicolons, prefer after-increment
        for (int i = 0; i < 25; i++) {
            // This is how we write loops
        }

        switch (var) {
            // Indentation for case label
            case 1: {
                int case_var{var + 3};
                DoSomething(case_var);
                break;
            }
            case 3:
                DoSomething(var);
                return;

            default:
                // Yes, even break for the last case
                break;
        }
    }
}
```