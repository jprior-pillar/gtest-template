# Notes from Neato Quality Framework meeting Friday, May 27, 2022

##################
# Notes from Neato Unit Test Sync Friday, May 27
#  Avinash, Mohammadreza, Kyle, Monica, Tiffany

** Highest Priority! **
Avinash was very interested in Accenture providing a 1-2 page guidelines/best practices
on "How to write unit tests using Gtest". He mentioned having a template that a Neato
dev would follow when creating a unit test from scratch or updating an existing unit
test. This guide would have the following:
1. How to structure unit tests
   a) Inherit from a base class with virtual functions
   b) File structure (single file vs multiple files)
   c) Grouping like tests together, breaking up unit tests
2. Creating mocks/fakes
3. Naming conventions for variables, methods, mocks/fakes
4. Setup/teardown (common is separate file?)
5. ???

Once we have Unit Test Guidelines doc the Neato devs will use it when they update old
or create new unit tests. We will use it for the old tests we modify.


Synopsis:
---------
Avinash said to assume the class are implemented as intended and to write the unit test
to test/verify the code as is in the class

Avinash liked the idea of using Doxygen to document what the unit tests were doing but
he felt that it would difficult for us to discern the requirements from just looking
at the class. So it would not be necessary to try to document the requirements in the
unit test, just what the test was testing.

We should write Jira tix if we don't understand what the class is doing (or an old unit test)
and Avinash/Mohammadreza would respond with an explanation. Avinash wanted to keep
the devs out of direct exchanges for this to force he and Mohammadreza to learn the code.
But he would bring a dev in if they needed help. Assign the tix to Avinash.

When we find bugs in the code we write a Jira tix, they will create a label for us to use
(no need to put "[Accenture]" in the Summary). Leave the Priority and Severity to defaults,
assign to Avinash.

When we recommend an improvement to the code we write a Jira tix and use a "Improvement" in
the "Issue" field. Assign to Avinash.

For code bugs or improvements, we will triage w/ Avinash/Mohammadreza to determine who will
fix (Neato or Accenture).

Releases:
---------
Avinash felt trying to sync our work with Neato releases weekly or periodically would be too
inefficient so he wants us to start with release 1.6.25-2319. We will work on that and at
some point do a massive merge to get our modified unit tests pushed to their origin.

Neato devs will inform us what modules/classes they are working on. We may decide to leave
those tests alone and/or work w/ dev to show them how to increase coverage while they
are updating the test to include the new functionality they are adding.

Currently their Bitbucket is locked from checking in. We are to continue using our Fork and
to our Fork on Bitbucket. We will convert to GitLab once we all have the necessary
permissions (Octo, GitLab).

Coverage:
---------
Avinash wants us to review the coverage reports and then the unit tests where coverage is less
than TBD%. For a start we'll say 90% (or 95%?) and look at those classes/unit tests below
that threshold.
1. Initially wants a report on categories of WHY tests are less than 90/95%/100%
   Missing functions, missing test cases, unreachable/dead code, error condition, etc
2. Then we will triage and work towards getting all tests up to 90-100%
3. Prioritize low hanging fruit to get jumps up to 80/90%
   We get to decide what we want to prioritize at this point
4. Wants end report on files missing 100% coverage
5. ???

Our Deliverables Priorities:
----------------------------
1. Unit Test Guidelines/Best Practices document
2. Review code coverage and create report on categories of missing coverage
   Explanation of low coverage
3. Start updating unit tests to increase coverage
4. Create Jira tix for code bugs, code improvements and to get clarification on class
   implementation (and unit test if necessary)
5. Implement error fixes or code improvements as determined by triage team
6. Look at class/code design/architecture and suggest improvements
   Avinash mentioned helping w/ abstraction in production code and TDD (unit tests)
