/**
 * \file dash/dart/if/dart_locality.h
 *
 * A set of routines to query and remodel the locality domain hierarchy
 * and the logical arrangement of teams.
 *
 */
#ifndef DART__LOCALITY_H_
#define DART__LOCALITY_H_

#include <dash/dart/if/dart_types.h>


/**
 * \defgroup  DartLocality  Locality- and topolgy discovery
 * \ingroup   DartInterface
 */
#ifdef __cplusplus
extern "C" {
#endif

#define DART_INTERFACE_ON

/**
 * Initialize information of the specified team.
 *
 * \ingroup DartLocality
 */
dart_ret_t dart_team_locality_init(
  dart_team_t                     team);

/**
 * Initialize information of the specified team.
 *
 * \ingroup DartLocality
 */
dart_ret_t dart_team_locality_finalize(
  dart_team_t                     team);

/**
 * Locality information of the team domain with the specified id tag.
 *
 * \ingroup DartLocality
 */
dart_ret_t dart_domain_team_locality(
  dart_team_t                     team,
  const char                    * domain_tag,
  dart_domain_locality_t       ** team_domain_out);

/**
 * Locality information of the subdomain with the specified id tag.
 *
 * \ingroup DartLocality
 */
dart_ret_t dart_domain_find(
  const dart_domain_locality_t  * domain_in,
  const char                    * domain_tag,
  dart_domain_locality_t       ** subdomain_out);

/**
 * Copy a locality domain object.
 *
 * \ingroup DartLocality
 */
dart_ret_t dart_domain_copy(
  const dart_domain_locality_t  * domain_in,
  dart_domain_locality_t        * domain_out);

/**
 * Delete a locality domain object.
 *
 * \ingroup DartLocality
 */
dart_ret_t dart_domain_destruct(
  dart_domain_locality_t        * domain);

/**
 * Remove domains in locality domain hierarchy that do not match the
 * specified domain tags and are not a parent of a matched domain.
 *
 * \ingroup DartLocality
 */
dart_ret_t dart_domain_select(
  dart_domain_locality_t        * domain_in,
  int                             num_subdomain_tags,
  const char                   ** subdomain_tags);

/**
 * Remove domains in locality domain hierarchy matching the specified domain
 * tags.
 *
 * \ingroup DartLocality
 */
dart_ret_t dart_domain_exclude(
  dart_domain_locality_t        * domain_in,
  int                             num_subdomain_tags,
  const char                   ** subdomain_tags);

/**
 * Split locality domain hierarchy at given domain tag into \c num_parts
 * groups at specified scope.
 *
 * \ingroup DartLocality
 */
dart_ret_t dart_domain_split(
  const dart_domain_locality_t  * domain_in,
  dart_locality_scope_t           scope,
  int                             num_parts,
  dart_domain_locality_t        * split_domain_out);

/**
 * Domain tags of all domains with the specified locality scope.
 *
 * \ingroup DartLocality
 */
dart_ret_t dart_domain_scope_tags(
  const dart_domain_locality_t  * domain_in,
  dart_locality_scope_t           scope,
  int                           * num_domains_out,
  char                        *** domain_tags_out);

/**
 * Adds entries to locality hierarchy to group locality domains.
 */
dart_ret_t dart_domain_group(
  dart_domain_locality_t        * domain_in,
  int                             num_group_subdomains,
  const char                   ** group_subdomain_tags,
  char                          * group_domain_tag_out);

/**
 * Locality information of the unit with the specified global id.
 *
 * \ingroup DartLocality
 */
dart_ret_t dart_unit_locality(
  dart_team_t                     team,
  dart_unit_t                     unit,
  dart_unit_locality_t         ** loc);

#define DART_INTERFACE_OFF

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* DART__LOCALITY_H_ */
